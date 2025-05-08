import csv
import time
import sys
import math

import math
import csv

# AVL Tree Node class
class AVLNode:
    def __init__(self, key, value=None):
        self.key = key              # curr gpa 
        self.value = value          # atudent name
        self.left = None            # Left child
        self.right = None           # Right child
        self.height = 1             # Height 

# AVL Tree class
class AVLTree:
    # Get the height of a node
    def get_height(self, node):
        return node.height if node else 0

    # Get balance factor of a node (left height - right height)
    def get_balance(self, node):
        return self.get_height(node.left) - self.get_height(node.right) if node else 0

    # Perform right rotation (for LL imbalance)
    def right_rotate(self, y):
        x = y.left
        T2 = x.right

        x.right = y
        y.left = T2

        # Update heights
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))

        return x

    # Perform left rotation (for RR imbalance)
    def left_rotate(self, x):
        y = x.right
        T2 = y.left

        y.left = x
        x.right = T2

        # Update heights
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        return y

    # Insert a node and maintain AVL balance
    def insert(self, root, key, value=None):
        """Insert into thhe Avl Tree, akigng care of the balancing. """
        if not root:
            return AVLNode(key, value)
        elif key < root.key:
            root.left = self.insert(root.left, key, value)
        elif key > root.key:
            root.right = self.insert(root.right, key, value)
        else:
            # If key exists, update its value
            root.value = value
            return root

        # Update height and balance the node
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balance = self.get_balance(root)

        # Balance the tree using appropriate rotations
        if balance > 1 and key < root.left.key:
            return self.right_rotate(root)
        if balance < -1 and key > root.right.key:
            return self.left_rotate(root)
        if balance > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)
        if balance < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    # Insert nodes without AVL balancing (just level-order)
    def insert_linear(self, root, key, value=None):
        """
        Insert into a general binary tree in a level-order fashion.
        """
        from collections import deque

        new_node = AVLNode(key, value)
        if root is None:
            return new_node

        queue = deque([root])
        while queue:
            current = queue.popleft()
            if current.left is None:
                current.left = new_node
                return root
            else:
                queue.append(current.left)

            if current.right is None:
                current.right = new_node
                return root
            else:
                queue.append(current.right)

        return root

    # Delete a node and re-balance the AVL tree
    def delete(self, root, key):
        if not root:
            return root
        elif key < root.key:
            root.left = self.delete(root.left, key)
        elif key > root.key:
            root.right = self.delete(root.right, key)
        else:
            # Node with one child or no child
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            # Node with two children: get in-order successor
            temp = self.min_value_node(root.right)
            root.key, root.value = temp.key, temp.value
            root.right = self.delete(root.right, temp.key)

        # Update height and balance the node
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balance = self.get_balance(root)

        # Re-balance the node if needed
        if balance > 1 and self.get_balance(root.left) >= 0:
            return self.right_rotate(root)
        if balance > 1 and self.get_balance(root.left) < 0:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)
        if balance < -1 and self.get_balance(root.right) <= 0:
            return self.left_rotate(root)
        if balance < -1 and self.get_balance(root.right) > 0:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    # In-order traversal: right → root → left in Desc order 
    def inorder(self, root, res=None):
        if res is None:
            res = []
        if root:
            self.inorder(root.right, res)
            res.append((root.key, root.value))
            self.inorder(root.left, res)
        return res

    # Helper to find the node with the smallest key in a subtree
    def min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current
    def find_node(self, root, key, name):
        """
        Search for a node whose key == key and whose value[0] ie the name matches
        Returns the AVLNode or None if not found.
        """
        if not root:
            return None
        if key < root.key:
            return self.find_node(root.left, key, name)
        elif key > root.key:
            return self.find_node(root.right, key, name)
        else:
            node_name, _prev = root.value
            if node_name.lower() == name.lower():
                return root
            # in case of duplicate keys, search both subtrees:
            left_hit = self.find_node(root.left, key, name)
            return left_hit or self.find_node(root.right, key, name)


# - Award Calculation Functions ----------------

# Get students in top 5% based on current GPA
def get_deans_list(students):
    sorted_current = sorted(students, key=lambda s: s[2], reverse=True)
    top_n = max(3, math.ceil(0.05 * len(sorted_current)))
    return sorted_current[:top_n]

# Get students in top 5% based on previous GPA
def get_previous_deans_list(students):
    sorted_prev = sorted(students, key=lambda s: s[1], reverse=True)
    top_n = max(3, math.ceil(0.05 * len(sorted_prev)))
    return sorted_prev[:top_n]

# Get students who are on both current and previous Dean's List
def get_presidents_list(students):
    prev = {s[0] for s in get_previous_deans_list(students)}
    curr = get_deans_list(students)
    return [s for s in curr if s[0] in prev]

# Get students who improved GPA by 0.5 or more
def get_high_leap_award(students):
    return [s for s in sorted(students, key=lambda s: s[2], reverse=True)
            if (s[2] - s[1]) >= 0.5]

# ------ CSV Data Loader ----------

# Load student GPA data from CSV file
def load_csv(path):
    data = []
    with open(path, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader, None)  # Skip header row
        for row in reader:
            if len(row) < 3:
                continue
            name = row[0].strip()
            try:
                prev = float(row[1])
                curr = float(row[2])
            except ValueError:
                continue
            data.append((name, prev, curr))
    return data

# Main CLI

def main():
    tree = AVLTree()
    avl_root = None
    linear_root = None
    students = []

    fname = input("Enter CSV filename (without .csv): ").strip()
    csv_path = f"{fname}.csv"
    students = load_csv(csv_path)
    print(f"Loaded {len(students)} records from {csv_path}\n")

    # Bulk AVL insert
    t0 = time.perf_counter()
    for name, prev, curr in students:
        avl_root = tree.insert(avl_root, curr, (name, prev))
    t1 = time.perf_counter()
    print(f"AVL insert: {len(students)} nodes in {t1-t0:.6f}s")

    # Bulk linear insert
    t0 = time.perf_counter()
    for name, prev, curr in students:
        linear_root = tree.insert_linear(linear_root, curr, (name, prev))
    t1 = time.perf_counter()
    print(f"Linear Tree insert: {len(students)} nodes in {t1-t0:.6f}s\n")

    # Interactive loop
    while True:
        print("Operations:")
        print(" 1) Insert record (AVL vs. Linear)")
        print(" 2) Delete by Student")
        print(" 3) Update record (rebuild AVL)")
        print(" 4) In-order traverse (AVL)")
        print(" 5) Dean's List")
        print(" 6) President's List")
        print(" 7) High Leap Award")
        print(" 8) Exit")
        choice = input("> ").strip()

        if choice == '1':
            name = input(" Name: ")
            try:
                prev = float(input(" Previous GPA: "))
                curr = float(input(" Current GPA: "))
            except ValueError:
                print(" Invalid GPAs.\n")
                continue
            students.append((name, prev, curr))
            # AVL insert timing
            t0 = time.perf_counter()
            avl_root = tree.insert(avl_root, curr, (name, prev))
            t1 = time.perf_counter()
            print(f" AVL insert took {t1-t0:.6f}s")
            # Linear insert timing
            t0 = time.perf_counter()
            linear_root = tree.insert_linear(linear_root, curr, (name, prev))
            t1 = time.perf_counter()
            print(f" Linear insert took {t1-t0:.6f}s\n")

        elif choice == '2':
            name = input(" Name of student to delete: ").strip()
            found = False
            for idx, (nm, pr, cu) in enumerate(students):
                if nm.lower() == name.lower():
                    found = True
                    gpa_to_delete = cu
                    students.pop(idx)  # Remove from list
                    avl_root = tree.delete(avl_root, gpa_to_delete)
                    # Rebuild linear tree
                    linear_root = None
                    for n2, p2, c2 in students:
                        linear_root = tree.insert_linear(linear_root, c2, (n2, p2))
                    print(f" Deleted '{name}' with GPA {gpa_to_delete}. Trees rebuilt.\n")
                    break
            if not found:
                print(f" No student named '{name}'.\n")


        elif choice == '3':
            name = input(" Name to update: ").strip()
            try:
                old_curr = float(input(" Old Current GPA: "))
            except ValueError:
                print(" Invalid GPA.\n")
                continue

            # Use the AVL tree to find the node in O(log n)
            target = tree.find_node(avl_root, old_curr, name)
            if not target:
                print(f" No student named '{name}' with GPA {old_curr}.\n")
                continue

            try:
                new_curr = float(input(" New Current GPA: "))
            except ValueError:
                print(" Invalid GPA.\n")
                continue

            # Extract previous GPA from the node’s value
            _, prev = target.value

            # 1) Delete the old node, 2) Insert the new one
            avl_root = tree.delete(avl_root, old_curr) # ensuring O(logn) time updates 
            avl_root = tree.insert(avl_root, new_curr, (name, prev))

            # Keep the students list in sync
            students = [
                (nm, pr, new_curr) if nm.lower() == name.lower() and cu == old_curr
                else (nm, pr, cu)
                for nm, pr, cu in students
            ]

            # Rebuild the linear tree
            linear_root = None
            for nm, pr, cu in students:
                linear_root = tree.insert_linear(linear_root, cu, (nm, pr))

            print(f" Updated '{name}' from GPA {old_curr} to {new_curr}. Trees rebuilt.\n")

        elif choice == '4':
            items = tree.inorder(avl_root)
            print(" In-order (GPA:(Name,PrevGPA)): ")
            for k, v in items:
                print(f"  {k}: {v}")
            print()

        elif choice == '5':
            for nm, pr, cu in get_deans_list(students):
                print(f"  {nm} — GPA {cu}")
            print()

        elif choice == '6':
            for nm, pr, cu in get_presidents_list(students):
                print(f"  {nm} — GPA {cu}, Prev {pr}")
            print()

        elif choice == '7':
            for nm, pr, cu in get_high_leap_award(students):
                print(f"  {nm} — GPA {cu}, Prev {pr} (⬆ {cu-pr:.2f})")
            print()

        elif choice == '8':
            print("Exiting.")
            sys.exit(0)

        else:
            print(" Invalid choice.\n")

if __name__ == '__main__':
    main()
