#ifndef LLRB_HPP
#define LLRB_HPP

#include <iostream>
#include "VoidRef.hpp"
#define Min(x,y)			(((x) < (y)) ? (x) : (y))
#define Max(x,y)			(((x) > (y)) ? (x) : (y))
#define ArraySize(x)		(sizeof(x) / (sizeof((x)[0])))
#define SafeDelete(x)		{ if (NULL != (x)) { delete (x);     (x) = NULL; } }

//Struct for the LLTB
template <typename ItemType>
struct LLTB_t
{
	VoidRef_t Ref;

	bool IsRed;

	LLTB_t<ItemType> *pLeft;
	LLTB_t<ItemType> *pRight;
};

//Class declaration for the leftleaningrebblack tree
template <class ItemType>
class LeftLeaningRedBlack
{
    private:
        LLTB_t<ItemType>* m_pRoot;

    public:
        LeftLeaningRedBlack(void);
        ~LeftLeaningRedBlack(void);

        bool IsEmpty(void) { return NULL == m_pRoot; }

        void FreeAll(void);
        void Free(LLTB_t<ItemType> *pNode);

        LLTB_t<ItemType>* NewNode(void);

        void* LookUp(const int value);

        bool Insert(VoidRef_t ref);
        LLTB_t<ItemType>* InsertRec(LLTB_t<ItemType> *pNode, VoidRef_t ref);

        void Delete(const int value);
        LLTB_t<ItemType>* DeleteRec(LLTB_t<ItemType> *pNode, const int value);
        LLTB_t<ItemType>* DeleteMin(LLTB_t<ItemType> *pNode);

        void SanityCheck(void);
        void SanityCheckRec(LLTB_t<ItemType> *pNode, bool isParentRed, int blackDepth, int &minBlack, int &maxBlack);

        int  KeyCount(void);
        int  KeyCountRec(LLTB_t<ItemType> *pNode);

        void LeafDepth(void);
        int  LeafDepthRec(LLTB_t<ItemType> *pNode, int depth, int ary[], int depthLimit, int blackDepth, int &minBlack, int &maxBlack);

        void Traverse(void);
        void TraverseRec(LLTB_t<ItemType> *pNode, int &prev);
};

//Default ctor
template <class ItemType>
LeftLeaningRedBlack<ItemType>::LeftLeaningRedBlack(void)
	:	m_pRoot(NULL)
{
}

//Class Dtor
template <class ItemType>
LeftLeaningRedBlack<ItemType>::~LeftLeaningRedBlack(void)
{
	Free(m_pRoot);
}

//Freeall function to free the root of value
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::FreeAll(void)
{
	Free(m_pRoot);

	m_pRoot = NULL;
}

//Free function to check if a there is a node and to free the node
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::Free(LLTB_t<ItemType> *pNode)
{
	if (NULL != pNode) {
		if (NULL != pNode->pLeft) {
			Free(pNode->pLeft);
		}
		if (NULL != pNode->pRight) {
			Free(pNode->pRight);
		}

		SafeDelete(pNode);
	}
}

//NewNode function to create a new node
template <class ItemType>
LLTB_t<ItemType>* LeftLeaningRedBlack<ItemType>::NewNode(void)
{
	LLTB_t<ItemType> *pNew = new LLTB_t<ItemType>;

	pNew->Ref.Key      = 0;
	pNew->Ref.pContext = NULL;
	pNew->IsRed        = true;
	pNew->pLeft        = NULL;
	pNew->pRight       = NULL;

	return pNew;
}

//Lookup function to search a node using a key
template <class ItemType>
void* LeftLeaningRedBlack<ItemType>::LookUp(int key)
{
	LLTB_t<ItemType> *pNode = m_pRoot;

	while (NULL != pNode) {
		if (key == pNode->Ref.Key) {
			return pNode->Ref.pContext;
		}
		else if (key < pNode->Ref.Key) {
			pNode = pNode->pLeft;
		}
		else {
			pNode = pNode->pRight;
		}
	}

	return NULL;
}

//function to return the value of a node is red
template <class ItemType>
static inline bool IsRed(LLTB_t<ItemType> *pNode)
{
	return ((NULL != pNode) && pNode->IsRed);
}

//function to rotate the tree left at a certain node
template <class ItemType>
static LLTB_t<ItemType>* RotateLeft(LLTB_t<ItemType> *pNode)
{
	LLTB_t<ItemType> *pTemp = pNode->pRight;
	pNode->pRight   = pTemp->pLeft;
	pTemp->pLeft    = pNode;
	pTemp->IsRed    = pNode->IsRed;
	pNode->IsRed    = true;

	return pTemp;
}

//function to rotate the tree to the right at a certain node
template <class ItemType>
static LLTB_t<ItemType>* RotateRight(LLTB_t<ItemType> *pNode)
{
	LLTB_t<ItemType> *pTemp = pNode->pLeft;
	pNode->pLeft    = pTemp->pRight;
	pTemp->pRight   = pNode;
	pTemp->IsRed    = pNode->IsRed;
	pNode->IsRed    = true;

	return pTemp;
}

//function to flip the color of the node and both its children
template <class ItemType>
static void ColorFlip(LLTB_t<ItemType> *pNode)
{
	pNode->IsRed = !pNode->IsRed;

	if (NULL != pNode->pLeft) {
		pNode->pLeft->IsRed  = !pNode->pLeft->IsRed;
	}

	if (NULL != pNode->pRight) {
		pNode->pRight->IsRed = !pNode->pRight->IsRed;
	}
}

//function to insert using the insert recursion function
template <class ItemType>
bool LeftLeaningRedBlack<ItemType>::Insert(VoidRef_t ref)
{
	m_pRoot = InsertRec(m_pRoot, ref);

	// The root node of a red-black tree must be black.
	m_pRoot->IsRed = false;

	return true;
}

//Insert recursion function
template <class ItemType>
LLTB_t<ItemType>* LeftLeaningRedBlack<ItemType>::InsertRec(LLTB_t<ItemType>* pNode, VoidRef_t ref)
{
	if (NULL == pNode) {
		pNode      = NewNode();
		pNode->Ref = ref;
		return pNode;
	}
#if defined(USE_234_TREE)
	if (IsRed(pNode->pLeft) && IsRed(pNode->pRight)) {
		ColorFlip(pNode);
	}
#endif

	//Checks to see if the value is already in the tree
	if (ref.Key == pNode->Ref.Key) {
		pNode->Ref = ref;
	}

	else {
		if (ref.Key < pNode->Ref.Key) {
			pNode->pLeft = InsertRec(pNode->pLeft, ref);
		}
		else {
			pNode->pRight = InsertRec(pNode->pRight, ref);
		}
	}

	if (IsRed(pNode->pRight) && (false == IsRed(pNode->pLeft))) {
		pNode = RotateLeft(pNode);
	}

	// Fix two reds in a row: this will rebalance a 4-node.
	if (IsRed(pNode->pLeft) && IsRed(pNode->pLeft->pLeft)) {
		pNode = RotateRight(pNode);
	}

	// If we perform the color flip here, the tree is assembled as a
	// mapping of a 2-3 tree.
#if !defined(USE_234_TREE)

	if (IsRed(pNode->pLeft) && IsRed(pNode->pRight)) {
		ColorFlip(pNode);
	}
#endif

	// Return the new root of the subtree that was just updated,
	// since rotations may have changed the value of this pointer.
	return pNode;
}

//
template <class ItemType>
static LLTB_t<ItemType>* MoveRedLeft(LLTB_t<ItemType> *pNode)
{
	//If the children are black, color flip
	ColorFlip(pNode);
	// But we may end up with a case where pRight has a red child.
	// Apply a pair of rotations and a color flip to make pNode a
	// red node, both of its children become black nodes, and pLeft
	// becomes a 3-node.
	if ((NULL != pNode->pRight) && IsRed(pNode->pRight->pLeft)) {
		pNode->pRight = RotateRight(pNode->pRight);
		pNode         = RotateLeft(pNode);

		ColorFlip(pNode);
	}

	return pNode;
}

//Moveredright function
template <class ItemType>
static LLTB_t<ItemType>* MoveRedRight(LLTB_t<ItemType> *pNode)
{
	ColorFlip(pNode);
	if ((NULL != pNode->pLeft) && IsRed(pNode->pLeft->pLeft)) {
		pNode = RotateRight(pNode);

		ColorFlip(pNode);
	}

	return pNode;
}

//Findmin to find the node with the smallest key value
template <class ItemType>
static LLTB_t<ItemType>* FindMin(LLTB_t<ItemType> *pNode)
{
	while (NULL != pNode->pLeft) {
		pNode = pNode->pLeft;
	}

	return pNode;
}

//Fixup function to preserve blacklink balance and fix and right-leaning red nodes
//and elminate 4nodes when backing out of recursive calls
template <class ItemType>
static LLTB_t<ItemType>* FixUp(LLTB_t<ItemType> *pNode)
{
	// Fix right-leaning red nodes.
	if (IsRed(pNode->pRight)) {
		pNode = RotateLeft(pNode);
	}
	if (IsRed(pNode->pLeft) && IsRed(pNode->pLeft->pLeft)) {
		pNode = RotateRight(pNode);
	}

	// Split 4-nodes.
	if (IsRed(pNode->pLeft) && IsRed(pNode->pRight)) {
		ColorFlip(pNode);
	}

	return pNode;
}

//Delete function 
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::Delete(const int key)
{
	if (NULL != m_pRoot) {
		m_pRoot = DeleteRec(m_pRoot, key);
		//force the root to be a black node
		if (NULL != m_pRoot) {
			m_pRoot->IsRed = false;
		}
	}
}

//Delete recursion function
template <class ItemType>
LLTB_t<ItemType>* LeftLeaningRedBlack<ItemType>::DeleteRec(LLTB_t<ItemType> *pNode, const int key)
{
	if (key < pNode->Ref.Key) {
		if (NULL != pNode->pLeft) {
			// If pNode and pNode->pLeft are black, we may need to
			// move pRight to become the left child if a deletion
			// would produce a red node.
			if ((false == IsRed(pNode->pLeft)) && (false == IsRed(pNode->pLeft->pLeft))) {
				pNode = MoveRedLeft(pNode);
			}

			pNode->pLeft = DeleteRec(pNode->pLeft, key);
		}
	}
	else {
		// If the left child is red, apply a rotation so we make
		// the right child red.
		if (IsRed(pNode->pLeft)) {
			pNode = RotateRight(pNode);
		}
		// Special case for deletion of a leaf node.
		// The arrangement logic of LLRBs assures that in this case,
		// pNode cannot have a left child.
		if ((key == pNode->Ref.Key) && (NULL == pNode->pRight)) {
			Free(pNode);
			return NULL;
		}
		if (NULL != pNode->pRight) {
			if ((false == IsRed(pNode->pRight)) && (false == IsRed(pNode->pRight->pLeft))) {
				pNode = MoveRedRight(pNode);
			}
			// Deletion of an internal node: We cannot delete this node
			// from the tree, so we have to find the node containing
			// the smallest key value that is larger than the key we're
			// deleting.  This other key will replace the value we're
			// deleting, then we can delete the node that previously
			// held the key/value pair we just moved.

			if (key == pNode->Ref.Key) {
				pNode->Ref    = FindMin(pNode->pRight)->Ref;
				pNode->pRight = DeleteMin(pNode->pRight);
			}
			else {
				pNode->pRight = DeleteRec(pNode->pRight, key);
			}
		}
	}

	return FixUp(pNode);
}

//Deletemin function to delete bottom node of the left spine and maintain balance
template <class ItemType>
LLTB_t<ItemType>* LeftLeaningRedBlack<ItemType>::DeleteMin(LLTB_t<ItemType> *pNode)
{
	//checks to see if this node has children
	if (NULL == pNode->pLeft) {
		Free(pNode);
		return NULL;
	}

	// If these nodes are black, we need to rearrange this subtree to
	// force the left child to be red.
	if ((false == IsRed(pNode->pLeft)) && (false == IsRed(pNode->pLeft->pLeft))) {
		pNode = MoveRedLeft(pNode);
	}

	// Continue recursing to locate the node to delete.
	pNode->pLeft = DeleteMin(pNode->pLeft);

	return FixUp(pNode);
}

//sanity check function
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::SanityCheck(void)
{
	if (NULL != m_pRoot) {
		int minBlack = 0xFFFFFFFF;
		int maxBlack = 0;

		// The root of the tree must always be a black node.
		//QzAssert(false == m_pRoot->IsRed);

		SanityCheckRec(m_pRoot, false, 0, minBlack, maxBlack);

		//QzAssert(minBlack == maxBlack);
	}
}

//Sanity check recursion
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::SanityCheckRec(LLTB_t<ItemType> *pNode, bool isParentRed, int blackDepth, int &minBlack, int &maxBlack)
{
	if (pNode->IsRed) {
		// The parent of a red node must be black.
		//QzAssert(false == isParentRed);

	}
	else {
		++blackDepth;
	}

	// The child of a red node must be black.
	if (isParentRed) {
		//QzAssert(false == pNode->IsRed);
	}

	// Only apply this test if the LLRB is arranged as a 2-3 tree.
	// Otherwise it is a 2-3-4 tree, in which case this rule does
	// not apply.
#if !defined(USE_234_TREE)
	// If the node has two children, only one of them may be red.
	// The other must be black.
	if ((NULL != pNode->pLeft) && (NULL != pNode->pRight)) {
		if (IsRed(pNode->pLeft)) {
			//QzAssert(false == IsRed(pNode->pRight));
		}
		if (IsRed(pNode->pRight)) {
			//QzAssert(false == IsRed(pNode->pLeft));
		}
	}
#endif

	if (NULL != pNode->pLeft) {
		// The left child must come before this node in sorting order.
		//QzAssert(pNode->pLeft->Ref.Key < pNode->Ref.Key);

		SanityCheckRec(pNode->pLeft, pNode->IsRed, blackDepth, minBlack, maxBlack);
	}
	else {
		minBlack = Min(minBlack, blackDepth);
		maxBlack = Max(maxBlack, blackDepth);
	}

	if (NULL != pNode->pRight) {
		// The right child must come after this node in sorting order.
		//QzAssert(pNode->pRight->Ref.Key > pNode->Ref.Key);

		SanityCheckRec(pNode->pRight, pNode->IsRed, blackDepth, minBlack, maxBlack);
	}
	else {
		minBlack = Min(minBlack, blackDepth);
		maxBlack = Max(maxBlack, blackDepth);
	}
}

//Keycount function to recursively count the keys in the tree
template <class ItemType>
int LeftLeaningRedBlack<ItemType>::KeyCount(void)
{
	return KeyCountRec(m_pRoot);
}

//Keycount recursion function to count
template <class ItemType>
int LeftLeaningRedBlack<ItemType>::KeyCountRec(LLTB_t<ItemType> *pNode)
{
	int tally = 0;

	if (NULL != pNode) {
		tally += 1;

		if (NULL != pNode->pLeft) {
			tally += KeyCountRec(pNode->pLeft);
		}

		if (NULL != pNode->pRight) {
			tally += KeyCountRec(pNode->pRight);
		}
	}

	return tally;
}

//Leafdepth function to test the "black depth" of every leaf node
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::LeafDepth(void)
{
	// This array will be used to track the number of nodes at each depth of the binary tree.
	int ary[64];
	for (int i = 0; i < ArraySize(ary); ++i) {
		ary[i] = 0;
	}

	int maxDepth = 0;
	int minBlack = 0xFFFFFFFF;
	int maxBlack = 0;

	if (NULL != m_pRoot) {
		maxDepth = LeafDepthRec(m_pRoot, 0, ary, ArraySize(ary), 0, minBlack, maxBlack);
	}

	int tally = 0;

	for (int i = 0; i < maxDepth; ++i) {
		tally += ary[i];

        std::cout << i << ": " << ary[i] << " = " << tally << std::endl;
	}

    std::cout << "black depth: " << minBlack << " to " << maxBlack << std::endl;
	//QzAssert(minBlack == maxBlack);
}

//Leafdepth recursion function to count
template <class ItemType>
int LeftLeaningRedBlack<ItemType>::LeafDepthRec(LLTB_t<ItemType> *pNode, int depth, int ary[], int depthLimit, int blackDepth, int &minBlack, int &maxBlack)
{
	ary[depth] += 1;

	if (false == pNode->IsRed) {
		++blackDepth;
	}

	// If this is a leaf node, return the total depth of this node.
	if ((NULL == pNode->pLeft) && (NULL == pNode->pRight)) {
		return depth + 1;
	}
	if (depth >= depthLimit) {
		return depth;
	}

	// Record the total depth along both the left and right children.
	int d1 = 0;
	int d2 = 0;

	if (NULL != pNode->pLeft) {
		d1 = LeafDepthRec(pNode->pLeft, depth + 1, ary, depthLimit, blackDepth, minBlack, maxBlack);
	}
	else {
		minBlack = Min(minBlack, blackDepth);
		maxBlack = Max(maxBlack, blackDepth);
	}

	if (NULL != pNode->pRight) {
		d2 = LeafDepthRec(pNode->pRight, depth + 1, ary, depthLimit, blackDepth, minBlack, maxBlack);
	}
	else {
		minBlack = Min(minBlack, blackDepth);
		maxBlack = Max(maxBlack, blackDepth);
	}

	// Return the maximum node depth found along this path from the root.
	return Max(d1, d2);
}

//Traverse function to perform an inorder traversal of the tree and print the key values
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::Traverse(void)
{
	if (NULL != m_pRoot) {
		int prev = 0;
		TraverseRec(m_pRoot, prev);
        std::cout << std::endl << std::endl;
	}
}

//Traverse recursion function to traverse through the tree
template <class ItemType>
void LeftLeaningRedBlack<ItemType>::TraverseRec(LLTB_t<ItemType> *pNode, int &prev)
{
	//QzAssert(NULL != pNode);

	if (NULL != pNode->pLeft) {
		TraverseRec(pNode->pLeft, prev);
	}

	//QzAssert(prev < pNode->Ref.Key);
	prev = pNode->Ref.Key;
	std::cout << pNode->Ref.Key << "\t" << (pNode->IsRed ? "Red" : "Black") << std::endl;

	if (NULL != pNode->pRight) {
		TraverseRec(pNode->pRight, prev);
	}
}



#endif