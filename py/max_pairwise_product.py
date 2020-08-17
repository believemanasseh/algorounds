import random

""" To test running time on *nix, run --time python3 max_pairwise_product.py-- """

def MaxPairwiseProduct(n):
	result = 0
	numbers = input().split()
	arr = list(map(int, numbers))

	for i in range(n):
		for j in range(i+1, n):
			if arr[i] * arr[j] > result:
				result = arr[i] * arr[j]
	return result

print(MaxPairwiseProduct(int(input())))


'''
Alternative Solution:

def MaxPairwiseProd(n):
	result = 0
	numbers = input().split()
	arr = list(map(int, numbers))

	if len(arr) == n:

		L1 = max(arr)
		arr.remove(L1)
		L2 = max(arr)
		result = L1 * L2

		return result

print(MaxPairwiseProd(int(input())))
'''

