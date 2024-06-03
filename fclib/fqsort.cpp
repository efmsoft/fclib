#include <proto.h>

// Note: This parameter defines the cutoff between using quick sort and
//       insertion sort for arrays; arrays with lengths shorter or equal to
//       the below value use insertion sort

#define CUTOFF                  8           // Testing shows that this is good
                                            // value

static void __cdecl swap(BYTE FAR* a, BYTE FAR* b, UINT width)
{
  BYTE tmp;

  if (a != b)                             // Do the swap one character at a
  {                                       // time to avoid potential
                                          // alignment problems.
    while (width--)
    {
      tmp = *a;
      *a++ = *b;
      *b++ = tmp;
    }
  }                                       // if ( a != b )
}

static void __cdecl shortsort(BYTE FAR* lo, BYTE FAR* hi,
  UINT       width, PQSORT_HANDLER comp)
{
  BYTE FAR* p;
  BYTE FAR* max;

  // Note: In assertions below, i and j are alway inside original bound of
  //       array to sort.

  while (hi > lo)
  {
    max = lo;                           // A[i] <= A[j] for i <= j, j > hi
    for (p = lo + width; p <= hi; p += width)
    {
      // A[i] <= A[max] for lo <= i < p
      if (comp(p, max) > 0)
      {
        max = p;
      }
      // A[i] <= A[max] for lo <= i <= p
    }

    // A[i] <= A[max] for lo <= i <= hi
    swap(max, hi, width);
    // A[i] <= A[hi] for i <= hi, so
    // A[i] <= A[j] for i <= j, j >= hi

    hi -= width;

    // A[i] <= A[j] for i <= j, j > hi,
    // loop top condition
    // established
  }
  // A[i] <= A[j] for i <= j, j >
  // lo, which implies A[i] <= A[j]
  // for i < j, so array is sorted
}

void FAR __cdecl _fqsort(void FAR* base, size_t         num,
  size_t     width, PQSORT_HANDLER comp)
{
  BYTE FAR* lo;                          // Ends of sub-array currently
  BYTE FAR* hi;                          // sorting
  BYTE FAR* mid;                         // points to middle of subarray
  BYTE FAR* higuy;                       // traveling pointers for
  BYTE FAR* loguy;                       // partition step
  UINT       size;                        // size of the sub-array
  BYTE FAR* lostk[30];                   // stack for saving sub-array to
  BYTE FAR* histk[30];                   // be processed
  int        stkptr;

  // Note: The number of stack entries required is no more than
  //       1 + log2(size), so 30 is sufficient for any array

  if (num < 2 || width == 0)
    return;                             // nothing to do

  stkptr = 0;                             // initialize stack

  lo = (BYTE FAR*)base;
  hi = (BYTE FAR*)base + width * (num - 1);// initialize limits

  // Note: This entry point is for pseudo-recursion calling: setting
  //       lo and hi and jumping to here is like recursion, but stkptr is
  //       prserved, locals aren't, so we preserve stuff on the stack */
recurse:

  size = UINT((hi - lo) / width + 1);     // number of el's to sort

  // Note: Below a certain size, it is faster to use a O(n^2) sorting method

  if (size <= CUTOFF)
  {
    shortsort(lo, hi, (UINT)width, comp);
  }
  else
  {

    // Note: First we pick a partititioning element.  The efficiency of the
    //       algorithm demands that we find one that is approximately the
    //       median of the values, but also that we select one fast.  Using
    //       the first one produces bad performace if the array is already
    //       sorted, so we use the middle one, which would require a very
    //       wierdly arranged array for worst case performance.  Testing shows
    //       that a median-of-three algorithm does not, in general, increase
    //       performance.

    mid = lo + (size / 2) * width;      // Find middle element
    swap(mid, lo, (UINT)width);         // Swap it to beginning of array

    // Note: We now wish to partition the array into three pieces, one
    //       consisiting of elements <= partition element, one of elements
    //       equal to the parition element, and one of element >= to it.  This
    //       is done below; comments indicate conditions established at every
    //       step.

    loguy = lo;
    higuy = hi + width;

    // Note that higuy decreases and loguy increases on every iteration,
    //       so loop must terminate.

    for (;;)
    {
      // Note: lo <= loguy < hi, lo < higuy <= hi + 1,
      //       A[i] <= A[lo] for lo <= i <= loguy,
      //       A[i] >= A[lo] for higuy <= i <= hi

      do
      {
        loguy += width;
      } while (loguy <= hi && comp(loguy, lo) <= 0);

      // Note: lo < loguy <= hi+1, A[i] <= A[lo] for lo <= i < loguy,
      //       either loguy > hi or A[loguy] > A[lo]

      do
      {
        higuy -= width;
      } while (higuy > lo && comp(higuy, lo) >= 0);

      // Note: lo-1 <= higuy <= hi, A[i] >= A[lo] for higuy < i <= hi,
      //       either higuy <= lo or A[higuy] < A[lo]

      if (higuy < loguy)
        break;

      // Note: if loguy > hi or higuy <= lo, then we would have exited, so
      //       A[loguy] > A[lo], A[higuy] < A[lo],
      //       loguy < hi, highy > lo

      swap(loguy, higuy, (UINT)width);

      // Note: A[loguy] < A[lo], A[higuy] > A[lo]; so condition at top
      //       of loop is re-established
    }

    // Note: A[i] >= A[lo] for higuy < i <= hi,
    //       A[i] <= A[lo] for lo <= i < loguy,
    //       higuy < loguy, lo <= higuy <= hi
    //       implying:
    //           A[i] >= A[lo] for loguy <= i <= hi,
    //           A[i] <= A[lo] for lo <= i <= higuy,
    //           A[i] = A[lo] for higuy < i < loguy

    swap(lo, higuy, (UINT)width);       // Put partition element in place

    // Note: OK, now we have the following:
    //       A[i] >= A[higuy] for loguy <= i <= hi,
    //       A[i] <= A[higuy] for lo <= i < higuy
    //       A[i] = A[lo] for higuy <= i < loguy
    //
    //       We've finished the partition, now we want to sort the subarrays
    //       [lo, higuy-1] and [loguy, hi].
    //       We do the smaller one first to minimize stack usage.
    //       We only sort arrays of length 2 or more.

    if (higuy - 1 - lo >= hi - loguy)
    {
      if (lo + width < higuy)
      {
        lostk[stkptr] = lo;
        histk[stkptr] = higuy - width;
        ++stkptr;
      }                               // Save big recursion for later

      if (loguy < hi)
      {
        lo = loguy;
        goto recurse;               // Do small recursion
      }
    }
    else
    {
      if (loguy < hi)
      {
        lostk[stkptr] = loguy;
        histk[stkptr] = hi;
        ++stkptr;                   // Save big recursion for later
      }

      if (lo + width < higuy)
      {
        hi = higuy - width;
        goto recurse;               // Do small recursion
      }
    }
  }

  // Note: We have sorted the array, except for any pending sorts on the stack.
  //       Check if there are any, and do them.

  --stkptr;

  if (stkptr >= 0)
  {
    lo = lostk[stkptr];
    hi = histk[stkptr];
    goto recurse;                       // Pop subarray from stack
  }
  else
    return;                             // All subarrays done
}
