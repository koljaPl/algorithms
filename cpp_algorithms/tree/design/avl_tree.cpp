#include <bits/stdc++.h>
using namespace std;

// AVL Tree:

// Height of AVL Tree:
// O( 1,44 * log2(n) )
//
// Time Complexity:
// Search:          O(log n)
// Insert:          O(log n)
// Remove:          O(log n)
//
// left_rotate():   O(1)
// right_rotate():  O(1)
//
// Space Complexity:
// Memory:          O(n)

class AVLTreeNode {
public:
    int value;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;

    AVLTreeNode(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
public:
    AVLTreeNode* root;

    AVLTree() {
        root = nullptr;
    }

    int get_height(AVLTreeNode* node) {
        return !node ? 0 : node->height;
    }

    int get_balance_factor(AVLTreeNode* node) {
        return !node ? 0 : get_height(node->left) - get_height(node->right);
    }

    AVLTreeNode* get_min_node(AVLTreeNode* node) {
        return !node || !node->left ? node : get_min_node(node->left);
    }

    // O(1)
    AVLTreeNode* left_rotate(AVLTreeNode* node) {
        AVLTreeNode* right = node->right;
        AVLTreeNode* left_right = right->left;

        right->left = node;
        node->right = left_right;

        node->height = 1 + max(get_height(node->left), get_height(node->right));
        right->height = 1 + max(get_height(right->left), get_height(right->right));

        return right;
    }

    // O(1)
    AVLTreeNode* right_rotate(AVLTreeNode* node) {
        AVLTreeNode* left = node->left;
        AVLTreeNode* right_left = left->right;

        left->right = node;
        node->left = right_left;

        node->height = 1 + max(get_height(node->left), get_height(node->right));
        left->height = 1 + max(get_height(left->left), get_height(left->right));

        return left;
    }

    // Worst Time Complexity: O(log n)
    AVLTreeNode* search(int target) {
        AVLTreeNode* curr = root;

        while (curr != nullptr && target != curr->value) {
            if (curr->value > target) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        return curr;
    }

    // Worst Time Complexity: O(log n)
    AVLTreeNode* insert(AVLTreeNode* node, int value) {
        if (!node) {
            return new AVLTreeNode(value);
        }
        else if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }

        node->height = 1 + max(get_height(node->left), get_height(node->right));

        int balance_factor = get_balance_factor(node);

        if (balance_factor > 1 && value < node->left->value) {
            return right_rotate(node);
        }

        if (balance_factor < -1 && value > node->right->value) {
            return left_rotate(node);
        }

        if (balance_factor > 1 && value > node->left->value) {
            node->left = left_rotate(node->left);

            return right_rotate(node);
        }

        if (balance_factor < -1 && value < node->right->value) {
            node->right = right_rotate(node->right);

            return left_rotate(node);
        }

        return node;
    }

    // Worst Time Complexity: O(log n)
    AVLTreeNode* delete_node(AVLTreeNode* node, int value) {
        if (!node) {
            return node;
        }
        else if (value < node->value) {
            node->left = delete_node(node->left, value);
        }
        else if (value > node->value) {
            node->right = delete_node(node->right, value);
        }
        else {
            if (!node->left) {
                AVLTreeNode* temp = node->right;

                delete node;

                return temp;
            }
            else if (!node->right) {
                AVLTreeNode* temp = node->left;

                delete node;

                return temp;
            }

            AVLTreeNode* temp = get_min_node(node->right);

            node->value = temp->value;

            node->right = delete_node(node->right, temp->value);
        }

        node->height = 1 + max(get_height(node->left), get_height(node->right));

        int balance_factor = get_balance_factor(node);

        if (balance_factor > 1 && get_balance_factor(node->left) >= 0) {
            return right_rotate(node);
        }

        if (balance_factor < -1 && get_balance_factor(node->right) <= 0) {
            return left_rotate(node);
        }

        if (balance_factor > 1 && get_balance_factor(node->left) < 0) {
            node->left = left_rotate(node->left);

            return right_rotate(node);
        }

        if (balance_factor < -1 && get_balance_factor(node->right) > 0) {
            node->right = right_rotate(node->right);

            return left_rotate(node);
        }

        return node;
    }

    // Worst Time Complexity: O(log n)
    void add(int value) {
        root = insert(root, value);
    }

    // Worst Time Complexity: O(log n)
    void remove(int value) {
        root = delete_node(root, value);
    }
};

// Intuition / Idea:
//
// Главная проблема: Почему обычное BST «ломается»?
// Представь, что мы вставляем в обычное бинарное дерево поиска (BST) отсортированные числа: 1, 2, 3, 4, 5.
// Дерево будет расти строго вправо. Вместо разветвленной структуры мы получим обычный связный список.
// В этот момент вся магия быстрого поиска рушится: вместо идеального времени O(log n) мы получаем худший сценарий - O(n).
// Нам приходится перебирать все элементы.
//
// Идея AVL-дерева: Жесткий контроль высоты
// Георгий Адельсон-Вельский и Евгений Ландис (отсюда и аббревиатура АВЛ) придумали гениальное правило:
// дерево должно контролировать свою форму в процессе роста или уменьшения. Они ввели понятие Фактора баланса (Balance Factor)
// для каждого узла: BF = height(Left) - height(Right).
// Золотое правило AVL: Для абсолютно любого узла в дереве его фактор баланса должен быть равен -1, 0 или 1.
// Если после вставки или удаления BF становится равен 2 или -2, это сигнал: «Дерево перекосило, срочно чиним!».
// Именно это ты и проверяешь в кодовой строке if balance_factor > 1 или if balance_factor < -1.
//
// Интуиция балансировки: Детская качель (мобиль)
//
// Представь себе весы провосудия как у древнегреческой богини Фемиды, нам для поддержания быстрого поиски, вставки и удаления
// нужен строгий баланс и если наше дерево куда лиюбо наклоняеться мы перекладываем грузики из одной чаши весов в другую.
//
// Чтобы вернуть равновесие, тебе нужно сменить точку опоры (pivot) — взять узел пониже и «вытянуть» его наверх, сделав новым
// центром тяжести поддерева. В коде эта смена точки опоры называется ротацией (вращением).
//
// Мой код для AVL обрабатывает 4 классических сценария перекоса:
//
// Случай 1: Одинарный перекос влево (Left-Left / LL)
//       Ситуация: Левое поддерево слишком длинное (BF > 1), и новый элемент ушел тоже влево (value < node.left.value).
//       Дерево выглядит как прямая линия, падающая влево. Решение:
//       right_rotate(node). Мы берем левого сына, тянем его вверх, а бывший корень «опускается» и становится его правым сыном.
//
// Случай 2: Одинарный перекос вправо (Right-Right / RR)
//       Ситуация: Зеркальна первому случаю. Правое поддерево перевешивает (BF < -1), элемент ушел вправо. Решение:
//       left_rotate(node) - Тянем правого сына вверх.
//
// Случай 3: Сложный перекос «Зигзаг» влево-вправо (Left-Right / LR)
//       Ситуация: Левое поддерево длиннее (BF > 1), но перевес вызван его правым внуком (value > node.left.value).
//       Дерево изогнуто зигзагом. Одинарный поворот тут не поможет — структура останется кривой. Решение:
//       Сначала мы делаем left_rotate для левого сына. Это «выпрямляет» зигзаг в прямую линию (превращает в случай LL).
//       А затем мы делаем финальный right_rotate для самого узла.
//
// Случай 4: Сложный перекос «Зигзаг» вправо-влево (Right-Left / RL)
//     Ситуация: Зеркальна предыдущему случаю. Правое поддерево тяжелее, но перевес ушел во внука-левее. Решение:
//     Выпрямляем зигзаг с помощью right_rotate для правого сына (превращая в RR), а затем балансируем через left_rotate исходного узла.