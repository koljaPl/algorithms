import pytest
from binary_search_tree import BinarySearchTree

@pytest.fixture
def bst():
    tree = BinarySearchTree()
    values = [5, 3, 7, 2, 4, 6, 8]
    for v in values:
        tree.insert(v)
    return tree


def inorder(node):
    if not node:
        return []
    return inorder(node.left) + [node.val] + inorder(node.right)


def test_insert_root():
    tree = BinarySearchTree()
    tree.insert(10)
    assert tree.root.val == 10


def test_insert_structure(bst):
    assert inorder(bst.root) == [2, 3, 4, 5, 6, 7, 8]


def test_search_found(bst):
    node = bst.search(4)
    assert node is not None
    assert node.val == 4


def test_search_not_found(bst):
    assert bst.search(100) is None


def test_delete_leaf(bst):
    bst.delete(2)
    assert inorder(bst.root) == [3, 4, 5, 6, 7, 8]


def test_delete_one_child():
    tree = BinarySearchTree()
    tree.insert(5)
    tree.insert(3)
    tree.insert(2)

    tree.delete(3)
    assert inorder(tree.root) == [2, 5]


def test_delete_two_children(bst):
    bst.delete(5)
    assert inorder(bst.root) == [2, 3, 4, 6, 7, 8]


def test_delete_nonexistent(bst):
    bst.delete(999)
    assert inorder(bst.root) == [2, 3, 4, 5, 6, 7, 8]


def test_empty_tree_search():
    tree = BinarySearchTree()
    assert tree.search(1) is None


def test_empty_tree_delete():
    tree = BinarySearchTree()
    tree.delete(1)  # не должно падать
    assert tree.root is None