import pytest

from avl_tree import AVLTree, AVLTreeNode

def is_balanced(tree, node):
    if not node:
        return True

    balance = tree.get_balance_factor(node)
    if abs(balance) > 1:
        return False

    return is_balanced(tree, node.left) and is_balanced(tree, node.right)


def is_bst(node, min_val=float('-inf'), max_val=float('inf')):
    if not node:
        return True
    if not (min_val < node.value < max_val):
        return False
    return is_bst(node.left, min_val, node.value) and \
        is_bst(node.right, node.value, max_val)


@pytest.fixture
def avl():
    return AVLTree()


def test_insert_single_node(avl):
    avl.root = avl.insert(avl.root, 10)
    assert avl.root.value == 10
    assert avl.root.height == 1


def test_ll_rotation(avl):
    avl.root = avl.insert(avl.root, 30)
    avl.root = avl.insert(avl.root, 20)
    avl.root = avl.insert(avl.root, 10)

    assert avl.root.value == 20
    assert avl.root.left.value == 10
    assert avl.root.right.value == 30
    assert is_balanced(avl, avl.root)


def test_rr_rotation(avl):
    avl.root = avl.insert(avl.root, 10)
    avl.root = avl.insert(avl.root, 20)
    avl.root = avl.insert(avl.root, 30)

    assert avl.root.value == 20
    assert avl.root.left.value == 10
    assert avl.root.right.value == 30
    assert is_balanced(avl, avl.root)


def test_lr_rotation(avl):
    avl.root = avl.insert(avl.root, 30)
    avl.root = avl.insert(avl.root, 10)
    avl.root = avl.insert(avl.root, 20)

    assert avl.root.value == 20
    assert is_balanced(avl, avl.root)


def test_rl_rotation(avl):
    avl.root = avl.insert(avl.root, 10)
    avl.root = avl.insert(avl.root, 30)
    avl.root = avl.insert(avl.root, 20)

    assert avl.root.value == 20
    assert is_balanced(avl, avl.root)


def test_search(avl):
    values = [10, 20, 30, 40, 50]
    for v in values:
        avl.root = avl.insert(avl.root, v)

    assert avl.search(30) is not None
    assert avl.search(30).value == 30
    assert avl.search(100) is None


def test_delete_leaf(avl):
    avl.root = avl.insert(avl.root, 10)
    avl.root = avl.insert(avl.root, 5)
    avl.root = avl.delete(avl.root, 5)
    assert avl.root.left is None
    assert avl.root.value == 10


def test_delete_node_with_two_children(avl):
    for v in [20, 10, 30, 5, 15, 25, 35]:
        avl.root = avl.insert(avl.root, v)

    avl.root = avl.delete(avl.root, 20)

    assert is_bst(avl.root)
    assert is_balanced(avl, avl.root)
    assert avl.search(20) is None


def test_complex_balancing(avl):
    for v in range(1, 11):
        avl.root = avl.insert(avl.root, v)

    assert is_balanced(avl, avl.root)
    assert is_bst(avl.root)

    for v in [1, 5, 10]:
        avl.root = avl.delete(avl.root, v)
        assert is_balanced(avl, avl.root)
        assert is_bst(avl.root)