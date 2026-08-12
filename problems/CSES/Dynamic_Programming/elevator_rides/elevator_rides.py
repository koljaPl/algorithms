import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main_v1():
    n, max_weight = map(int, input().split())
    weights = list(map(int, input().split()))

    total_masks = 1 << n

    dp = [(n + 1, 0)] * total_masks
    dp[0] = (1, 0)

    for mask in range(total_masks):
        rides, last_weight = dp[mask]

        for person in range(n):
            if mask & (1 << person):
                continue

            next_mask = mask | (1 << person)

            if last_weight + weights[person] <= max_weight:
                candidate = (
                    rides,
                    last_weight + weights[person]
                )
            else:
                candidate = (
                    rides + 1,
                    weights[person]
                )

            if candidate < dp[next_mask]:
                dp[next_mask] = candidate

    print(dp[total_masks - 1][0])

def main():
    n, max_weight = map(int, input().split())
    weights = list(map(int, input().split()))

    total_masks = 1 << n

    rides = [n + 1] * total_masks
    last_weight = [0] * total_masks

    rides[0] = 1

    weight_by_bit = [0] * total_masks
    for person, weight in enumerate(weights):
        weight_by_bit[1 << person] = weight

    for mask in range(1, total_masks):
        best_rides = n + 1
        best_last_weight = 0

        remaining = mask

        while remaining:
            bit = remaining & -remaining
            previous_mask = mask ^ bit
            weight = weight_by_bit[bit]

            candidate_rides = rides[previous_mask]
            candidate_weight = last_weight[previous_mask] + weight

            if candidate_weight > max_weight:
                candidate_rides += 1
                candidate_weight = weight

            if (
                candidate_rides < best_rides
                or (
                    candidate_rides == best_rides
                    and candidate_weight < best_last_weight
                )
            ):
                best_rides = candidate_rides
                best_last_weight = candidate_weight

            remaining ^= bit

        rides[mask] = best_rides
        last_weight[mask] = best_last_weight

    print(rides[-1])

main()
