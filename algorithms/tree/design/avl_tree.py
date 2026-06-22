from collections import deque

# AVL Tree:
# Height of AVL Tree:
# O( 1,44 * log2(n) )
#
# Time Complexity:
# Search:           O(log n)
# Insert:           O(log n)
# Remove:           O(log n)
#
# left_rotate():    O(1)
# right_rotate():   O(1)
#
# Space Complexity:
# Memory:           O(n)

class AVLTreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def __init__(self):
        self.root = None

    def get_height(self, node):
        return 0 if not node else node.height

    def get_balance_factor(self, node):
        return 0 if not node else (self.get_height(node.left) - self.get_height(node.right))

    def get_min_node(self, node):
        return node if not node or not node.left else self.get_min_node(node.left)

    # O(1)
    def left_rotate(self, node):
        right = node.right
        left_right = right.left

        right.left = node
        node.right = left_right

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        right.height = 1 + max(self.get_height(right.left), self.get_height(right.right))

        return right

    # O(1)
    def right_rotate(self, node):
        left = node.left
        right_left = left.right

        left.right = node
        node.left = right_left

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        left.height = 1 + max(self.get_height(left.left), self.get_height(left.right))

        return left

    # Worst Time Complexity: O(log n)
    def search(self, target):
        curr = self.root

        while curr is not None and target != curr.value:
            if curr.value > target:
                curr = curr.left
            else:
                curr = curr.right

        return curr

    # Worst Time Complexity: O(log n)
    def insert(self, node, value):
        if not node:
            return AVLTreeNode(value)
        elif value < node.value:
            node.left = self.insert(node.left, value)
        else:
            node.right = self.insert(node.right, value)

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

        balance_factor = self.get_balance_factor(node)

        if balance_factor > 1 and value < node.left.value:
            return self.right_rotate(node)

        if balance_factor < -1 and value > node.right.value:
            return self.left_rotate(node)

        if balance_factor > 1 and value > node.left.value:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)

        if balance_factor < -1 and value < node.right.value:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)

        return node

    # Worst Time Complexity: O(log n)
    def delete(self, node, value):
        if not node:
            return node
        elif value < node.value:
            node.left = self.delete(node.left, value)
        elif value > node.value:
            node.right = self.delete(node.right, value)
        else:
            if not node.left:
                temp = node.right
                node = None
                return temp
            elif not node.right:
                temp = node.left
                node = None
                return temp

            temp = self.get_min_node(node.right)
            node.value = temp.value
            node.right = self.delete(node.right, temp.value)

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

        balance_factor = self.get_balance_factor(node)

        if balance_factor > 1 and self.get_balance_factor(node.left) >= 0:
            return self.right_rotate(node)

        if balance_factor < -1 and self.get_balance_factor(node.right) <= 0:
            return self.left_rotate(node)

        if balance_factor > 1 and self.get_balance_factor(node.left) < 0:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)

        if balance_factor < -1 and self.get_balance_factor(node.right) > 0:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)

        return node

    # Worst Time Complexity: O(log n)
    def add(self, value):
        self.root = self.insert(self.root, value)

    # Worst Time Complexity: O(log n)
    def remove(self, value):
        self.root = self.delete(self.root, value)

# Intuition / Idea:
#
# Главная проблема: Почему обычное BST «ломается»?
# Представь, что мы вставляем в обычное бинарное дерево поиска (BST) отсортированные числа: 1, 2, 3, 4, 5.
# Дерево будет расти строго вправо. Вместо разветвленной структуры мы получим обычный связный список.
# В этот момент вся магия быстрого поиска рушится: вместо идеального времени O(log n) мы получаем худший сценарий - O(n).
# Нам приходится перебирать все элементы.
#
# Идея AVL-дерева: Жесткий контроль высоты
# Георгий Адельсон-Вельский и Евгений Ландис (отсюда и аббревиатура АВЛ) придумали гениальное правило:
# дерево должно контролировать свою форму в процессе роста или уменьшения. Они ввели понятие Фактора баланса (Balance Factor)
# для каждого узла: BF = height(Left) - height(Right).
# Золотое правило AVL: Для абсолютно любого узла в дереве его фактор баланса должен быть равен -1, 0 или 1.
# Если после вставки или удаления $BF$ становится равен 2 или -2, это сигнал: «Дерево перекосило, срочно чиним!».
# Именно это ты и проверяешь в кодовой строке if balance_factor > 1 или if balance_factor < -1.
#
# Интуиция балансировки: Детская качель (мобиль)
#
# Представь детскую игрушку-мобиль, которая висит над кроваткой, или весы с чашами. Если на левую сторону подвесить слишком
# много игрушек, вся конструкция перекосится влево.
#
# Чтобы вернуть равновесие, тебе нужно сменить точку опоры (pivot) — взять узел пониже и «вытянуть» его наверх, сделав новым
# центром тяжести поддерева. В коде эта смена точки опоры называется ротацией (вращением).
#
# Мой код для AVL обрабатывает 4 классических сценария перекоса:
#
# Случай 1: Одинарный перекос влево (Left-Left / LL)
#       Ситуация: Левое поддерево слишком длинное ($BF > 1$), и новый элемент ушел тоже влево (value < node.left.value).
#       Дерево выглядит как прямая линия, падающая влево. Решение:
#       right_rotate(node). Мы берем левого сына, тянем его вверх, а бывший корень «опускается» и становится его правым сыном.
#
# Случай 2: Одинарный перекос вправо (Right-Right / RR)
#       Ситуация: Зеркальна первому случаю. Правое поддерево перевешивает (BF < -1), элемент ушел вправо. Решение:
#       left_rotate(node) - Тянем правого сына вверх.
#
# Случай 3: Сложный перекос «Зигзаг» влево-вправо (Left-Right / LR)
#       Ситуация: Левое поддерево длиннее (BF > 1), но перевес вызван его правым внуком (value > node.left.value).
#       Дерево изогнуто зигзагом. Одинарный поворот тут не поможет — структура останется кривой. Решение:
#       Сначала мы делаем left_rotate для левого сына. Это «выпрямляет» зигзаг в прямую линию (превращает в случай LL).
#       А затем мы делаем финальный right_rotate для самого узла.
#
# Случай 4: Сложный перекос «Зигзаг» вправо-влево (Right-Left / RL)
#     Ситуация: Зеркальна предыдущему случаю. Правое поддерево тяжелее, но перевес ушел во внука-левее. Решение:
#     Выпрямляем зигзаг с помощью right_rotate для правого сына (превращая в RR), а затем балансируем через left_rotate исходного узла.
