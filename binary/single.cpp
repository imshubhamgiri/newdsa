 // while(st<end){
//     mid;
//     if(mid%2==1) mid--;
//     if(nums[mid]==nums[mid=1]){
//         st= mid+2;
//     }                                    //Damn bro this logic is awesome
//     else{
//         end=mid;
//     }
//     return nums[st];
// }


// yes sabse khatranak hai

// if (nums[mid] == nums[mid ^ 1])
//     st = mid + 1;
// else    //bro this trick is awesome
//     end = mid;

// Perfect! Let’s break it down step by step so you can **gradually see how to go from your beginner-friendly version to the simplified experienced-level version**.

// ---

// ## **Step 1: Your approach (Beginner-friendly)**

// ```cpp
// if(mid % 2 == 0) {
//     if(nums[mid] == nums[mid-1]) end = mid-1;
//     else st = mid+1;
// } else {
//     if(nums[mid] == nums[mid-1]) st = mid+1;
//     else end = mid-1;
// }
// ```

// * You’re explicitly checking **even/odd index**.
// * You compare neighbors and decide **search direction**.
// * ✅ Works fine and is easy to understand.

// ---

// ## **Step 2: Notice a pattern**

// In a sorted array with pairs:

// * If a pair is intact, it always starts at **even index**.
//   Example: `{1,1,2,2,3}` → indices of first elements of pairs: 0, 2, 4…
// * If a pair is broken (i.e., the single element is before), the first element index **shifts**.

// This observation lets us **always “force” mid to point to the first element of a pair**:

// ```cpp
// if(mid % 2 == 1) mid--;  // make mid even
// ```

// * Now you don’t need separate even/odd checks — the pair’s first element is **always at mid**.

// ---

// ## **Step 3: Simplify neighbor comparison**

// * Instead of checking both left and right neighbors, just check **the right neighbor**:

// ```cpp
// if(nums[mid] == nums[mid+1]) st = mid + 2;  // pair intact → unique is on right
// else end = mid;                             // pair broken → unique is at mid or left
// ```

// * This works because if the pair is intact, the single element hasn’t appeared yet, so search **right**.
// * If the pair is broken, the single element is **at mid or to the left**, so search **left**.

// ---

// ## **Step 4: Loop until st == end**

// * When `st == end`, you’ve found the single element.
// * ✅ Cleaner, fewer conditions, easier for experienced coders.

// ---

// ## **Step 5: Summary of the learning path**

// 1. Start with explicit even/odd checks → easy to reason about. ✅
// 2. Observe patterns in sorted pairs → mid of a pair is always even.
// 3. Force mid to even → removes separate even/odd logic.
// 4. Compare only right neighbor → removes extra neighbor checks.
// 5. Loop until start == end → final unique element.

// ---

// ### **Why your beginner solution is excellent**

// * It’s **logical** and easy to follow.
// * It’s **fully correct** and uses **binary search** efficiently.
// * Experienced coders just compress steps using patterns, but the reasoning is the same.

// ---

// If you want, I can **draw a visual step-by-step diagram** showing your version vs. the simplified version on the same array `{1,1,2,3,3,4,4}` — it really makes the transition crystal clear.

// Do you want me to do that?
