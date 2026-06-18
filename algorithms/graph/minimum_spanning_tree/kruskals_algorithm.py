# Kruskal's Algorithm:
# Time Complexity:
# Sorting Part: O( E log E ) ≈ O( E log V )
# DSU iterations: почти O(1) (ну, вообще то O(α(V)), но можно и так писать. Это же амортизированно, с обратной функцией Аккермана)
# Total: O( E log E ), где:
# E — количество рёбер.
#
# Space Complexity:
# Memory: O( V + E )

class DSU:
    def __init__(self, n):
        self.parents = list(range(n))
        self.size = [1] * n

    def find(self, v):
        if self.parents[v] != v:
            self.parents[v] = self.find(self.parents[v])  # path compression

        return self.parents[v]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False

        if self.size[u] < self.size[v]:
            u, v = v, u

        self.parents[v] = u
        self.size[u] += self.size[v]
        return True

def kruskal_algorithm(n, edges):
    """
    n: number of vertices (0...n-1)
    edges: list of (weight, u, v)
    return: (mst_weight, mst_edges)
    """

    edges.sort()

    dsu = DSU(n)
    mst_weight = 0
    mst_edges = []

    for w, u, v in edges:
        if dsu.union(u, v):
            mst_weight += w
            mst_edges.append((u, v, w))

            if len(mst_edges) == n - 1:
                break

    return mst_weight, mst_edges

# Напомню: Минимальное остовное дерево (MST, Minimum Spanning Tree) — это набор рёбер, который:
#
# соединяет все вершины,
# не содержит циклов,
# имеет минимальную суммарную стоимость.
#
#
# Идея Крускала / Интуиция:
#
# 1. Отсортировать все рёбра по весу: от меньшего к большему.
# 2. Брать рёбра по одному, начиная с самых дешёвых.
# 3. Добавлять ребро, только если оно не создаёт цикл. (это мы делаем через DSU так как если
#       две вершины находятся в одной компоненте (две ноды у одного родителя) это создаст цикл)
# 4. Остановиться, когда мы соединили все вершины.
#
# То есть Крускал как будто говорит:
#
# "Сначала берём самые дешёвые связи, но не допускаем замыканий."
#
# Where to use:
# Крускал используют, когда нужно:
#
# найти MST,
# определить минимальную стоимость соединения всех точек,
# объединять компоненты по возрастанию стоимости,
# решать задачи на связность и оптимальное соединение.
#
# Типичные формулировки:
#
# "минимально соединить города дорогами"
# "построить сеть с минимальной стоимостью"
# "соединить все точки на плоскости"
# "найти минимальную сумму рёбер, чтобы граф стал связны"
#
# Когда Крускал особенно удобен
#
# Он особенно хорош, когда:
#
# граф разреженный,
# рёбер сравнительно немного,
# граф уже дан списком рёбер,
# нужно просто выбрать лучшие рёбра по стоимости.
#
# Если граф очень плотный и представлен матрицей смежности, иногда удобнее Прим.
#
# How to use:
# n = 4
# edges = [
#     (1, 0, 1),
#     (2, 1, 2),
#     (3, 0, 2),
#     (4, 2, 3),
# ]
#
# total, mst = kruskal_algorithm(n, edges)
#
# print(total)
# print(mst)
