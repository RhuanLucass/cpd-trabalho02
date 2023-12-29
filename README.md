# Practical Work II - Data Classification and Search

**Group:** Davi Santos Ferrarez, Rhuan Lucas Barbosa Fernandes  
**Course:** Computer Engineering  

## Experiment 1 - Comparison of Key Transformation Algorithms (Hashing)

### Introduction
Experiment 1 aims to compare the execution time for insertion and search in different types of key transformation algorithms (hashing). The hash table is a generalization of a vector with associations between keys and values, aiming for quick search through a simple key to find the desired value.

### Table (time in seconds) and Discussion of Results
#### Test 1
- Vector size: 100,000
- Open addressing vector size: 200,000
- Chained list vector size: 5,000

| Algorithm     | Linear Probing | Quadratic Probing | Chained List |
|---------------|----------------|--------------------|--------------|
| Insertion     | 0.004          | 0.002              | 0.012        |
| Search        | 0.005          | 0.002              | 0.019        |

#### Test 2
- Vector size: 100,000 elements
- Open addressing vector size: 100001
- Chained list vector size: 99999

| Algorithm     | Linear Probing | Quadratic Probing | Chained List |
|---------------|----------------|--------------------|--------------|
| Insertion     | 0.005          | 0.003              | 0.012        |
| Search        | 0.005          | 0.002              | 0.020        |

#### Test 3
- Vector size: 100,000 elements
- Open addressing vector size: 150,000
- Chained list vector size: 50,000

| Algorithm     | Linear Probing | Quadratic Probing | Chained List |
|---------------|----------------|--------------------|--------------|
| Insertion     | 0.004          | 0.002              | 0.011        |
| Search        | 0.004          | 0.001              | 0.020        |

### Conclusion
Through the tests, it was observed that open addressing hashing with quadratic probing achieved the best time in all attempts. This is due to the fact that quadratic probing finds a free position in the vector more quickly than linear probing. Additionally, the hash table with a chained list traverses the entire key-related list, resulting in a longer time.

## Experiment 2 - Binary Search Tree (BST) and AVL Tree

### Introduction
Experiment 2 compares two algorithms: Binary Search Tree (BST) and AVL Tree. In a BST, each node is an object containing attributes left, right, and p, while an AVL is balanced, ensuring that the height difference between right and left subtrees is 1, 0, or -1.

### Table (time in seconds) and Discussion of Results
- Insertion time
- Search time
- Removal time

| Algorithm | Insertion | Search | Removal |
|-----------|-----------|--------|---------|
| BST       | 0.002     | 0.001  | 0.227   |
| AVL       | 0.002     | 0.001  | 0.259   |

### Conclusion
It was observed that insertion and search times in both algorithms are approximately equal. However, AVL has a lower removal time compared to BST. The search time in both algorithms is faster than the insertion time. The removal time in both trees is considerably longer compared to the other cases.

To access the complete work, use the following links:
- [Experiment 1 on GitHub](https://github.com/RhuanLucass/cpd-trabalho02/tree/master/Experimento1)
- [Experiment 2 on GitHub](https://github.com/RhuanLucass/cpd-trabalho02/blob/master/Experimento2/main.c)
