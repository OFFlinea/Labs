import matplotlib.pyplot as plt


with open("insertion_sort_results.txt", "r") as f:
    y1 = list(map(float, f.readline().strip().split()))

with open("bin1_insertion_sort_results.txt", "r") as f:
    y2 = list(map(float, f.readline().strip().split()))

with open("bin2_insertion_sort_results.txt", "r") as f:
    y3 = list(map(float, f.readline().strip().split()))

x = [i for i in range(0, 1000001, 10000)]

plt.plot(x, y1, label='Insertion Sort')
plt.plot(x, y2, label='Binary Insert Sort (recursive)')
plt.plot(x, y3, label='Binary Insert Sort (iterative)')
plt.title('Insertion sort algorithms comparison')
plt.xlabel('Size')
plt.ylabel('Time, usec')
plt.legend()
plt.show()