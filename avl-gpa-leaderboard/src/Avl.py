import sys
import csv
import math
import io
import sys
#sys.setrecursionlimit(50000)   

import networkx as nx
import matplotlib.pyplot as plt
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QPushButton, QFileDialog, QMessageBox, QLabel, QComboBox, QTextEdit, QFrame, QLineEdit,QScrollArea
)
from PyQt5.QtGui import QPixmap, QImage, QPainter, QPen, QFont
from PyQt5.QtCore import Qt

# -------------------------------
# AVL Tree Implementation

class AVLNode:
    """
    Node class for AVL Tree, storing student name, current GPA, previous GPA, and height.
    """
    def __init__(self, name, current_gpa, previous_gpa):
        self.name = name                    # Student name
        self.current_gpa = current_gpa      # Current GPA  
        self.previous_gpa = previous_gpa    # Previous GPA
        self.left = None
        self.right = None
        self.height = 1                     # Height of node

class AVLTree:
    """
    AVL Tree class implementing insertion, balancing, and inorder traversal.
    """
    def get_height(self, node):
        return node.height if node else 0

    def get_balance(self, node): # left subtree - right subtree for balance 
        return self.get_height(node.left) - self.get_height(node.right) if node else 0

    def right_rotate(self, y):
        # Base case ->  if NOde is None or doesn't have a left child, rotation isn't possible
        if y is None or y.left is None:
            return y
        # rotation steps: 
        x = y.left # x becomes the new root after rotation
        T2 = x.right  # T2 becomes the right of x ie new left child of y
        x.right = y # make y the right of x 
        y.left = T2 # T2 becomes left of y 

        # updatIng Heights 
        y.height = max(self.get_height(y.left), self.get_height(y.right)) + 1
        x.height = max(self.get_height(x.left), self.get_height(x.right)) + 1
        return x

    def left_rotate(self, x):
        #base case if node is None or doesnt have a right child, Rotation isnt possible 
        if x is None or x.right is None:
            return x
        # roation steps 
        y = x.right
        T2 = y.left
        y.left = x
        x.right = T2
        #Updating heights
        x.height = max(self.get_height(x.left), self.get_height(x.right)) + 1
        y.height = max(self.get_height(y.left), self.get_height(y.right)) + 1
        return y

    def insert(self, root, name, current_gpa, previous_gpa):
        
        if not root:
            # If the current subtree is empty create New Nodde
            return AVLNode(name, current_gpa, previous_gpa)

        # If current GPA is less than the root's GPA, go to left subtree
        if current_gpa < root.current_gpa:
            root.left = self.insert(root.left, name, current_gpa, previous_gpa)
        else:
            # otherwise go to right subtree
            root.right = self.insert(root.right, name, current_gpa, previous_gpa)
        # Updating height 
        root.height = max(self.get_height(root.left), self.get_height(root.right)) + 1
        balance = self.get_balance(root) # getting balance factor 
        # Case 1: Left Left 
        if balance > 1 and current_gpa < root.left.current_gpa:
            return self.right_rotate(root)
        # Case 2: Right Right 
        if balance < -1 and current_gpa > root.right.current_gpa:
            return self.left_rotate(root)
        # Case 3: Left Right 
        if balance > 1 and current_gpa > root.left.current_gpa:
            root.left = self.left_rotate(root.left)  # First left rotate child
            return self.right_rotate(root)           # Then right rotate root
        # Case 4: Right Left 
        if balance < -1 and current_gpa < root.right.current_gpa:
            root.right = self.right_rotate(root.right)  # First right rotate child
            return self.left_rotate(root)               # Then left rotate root

        # If no rotation is needed, return the root as is
        return root
    def delete(self, root, current_gpa):
        """
        Delete the node with matching current_gpa and rebalance the AVL tree.
        """
        if root is None:
            return None

        # 1) Traverse to find the node
        if current_gpa < root.current_gpa:
            root.left = self.delete(root.left, current_gpa)
        elif current_gpa > root.current_gpa:
            root.right = self.delete(root.right, current_gpa)
        else:
            # 2) Found the node to delete
            # Case A: one or no child
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left

            # Case B: two children — find in-order successor
            succ = self.min_value_node(root.right)
            # Copy successor's data into this node
            root.name = succ.name
            root.current_gpa = succ.current_gpa
            root.previous_gpa = succ.previous_gpa
            # Delete the successor
            root.right = self.delete(root.right, succ.current_gpa)

        # 3) Update height
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))

        # 4) Rebalance
        balance = self.get_balance(root)
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

    # Helper to find the node with the smallest key in a subtree
    def min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current
    def inorder_traversal(self, root, result=None):
            # inorder travlersal in form Right,Node,Left to get results in desc order
            if result is None:
                result = []
            if root:
                self.inorder_traversal(root.right, result)
                result.append(root)
                self.inorder_traversal(root.left, result)
            return result
    # --- add into your AVLTree class ---
    def find_node(self, root, target_gpa, target_name): # Searching in O(logn) time
        """
        Recursively locate the node whose current_gpa == target_gpa
        and whose name matches (case-insensitive). Returns the node or None.
        """
        if root is None:
            return None

        # Step down the tree by GPA
        if target_gpa < root.current_gpa:
            return self.find_node(root.left, target_gpa, target_name)
        elif target_gpa > root.current_gpa:
            return self.find_node(root.right, target_gpa, target_name)
        else:
            # GPA matches
            if root.name.lower() == target_name.lower():
                return root
            # If duplicates exist, search left then right
            left_hit = self.find_node(root.left, target_gpa, target_name)
            return left_hit or self.find_node(root.right, target_gpa, target_name)


# ---------
# Award Calculation Functions

def get_deans_list(tree, root):
    nodes = tree.inorder_traversal(root) # get all students in descending order of gpa
    count = len(nodes) # total number of students for top 5% calculations
    top_count = max(3, math.ceil(0.05 * count)) # minimum 3 students
    return nodes[:top_count] # return top 5% students
def get_previous_deans_list(tree, root):
    """
    Return top 5% of students by previous GPA (at least one student).
    """
    #Retrieve all nodes in desc by current GPA but it includes previous data as well
    all_nodes = tree.inorder_traversal(root)
    # Sort by previous GPA in descending order
    sorted_prev = sorted(all_nodes, key=lambda n: n.previous_gpa, reverse=True)
    # top 5% students computed 
    count = len(sorted_prev)
    top_count = max(3, math.ceil(0.05 * count)) # minimum 3 students
    # SliCING  and returning  only that top segment
    return sorted_prev[:top_count]


def get_presidents_list(tree, root):
    """
    Presidents list: students who made Dean's List both last semester and this semester.
    """
    prev_deans = get_previous_deans_list(tree, root) # get deans list students of previous semester
    current_deans = get_deans_list(tree, root) # current deans listers
    prev_names = {node.name for node in prev_deans}
    # Intersection - those in both lists will be part of presidents list
    presidents = [node for node in current_deans if node.name in prev_names]
    return presidents 


def get_high_leap_award(tree, root):
    nodes = tree.inorder_traversal(root) # get all students in desc order of gpa 
    
    # Filter students who had a GPA increase >= 0.5
    awardees = [node for node in nodes if node.previous_gpa is not None and (node.current_gpa - node.previous_gpa) >= 0.5]
    return awardees

# -------------------------------
#  Hierarchical Layout for  Displaying AVL Tree (adapted from https://stackoverflow.com/a/29597209)

# For the exact position of the node in the tree ie left or right (x or y)
"""def hierarchy_pos(G, root, width=1.0, vert_gap=0.2, vert_loc=0, xcenter=0.5, pos=None, parent=None):
#    global x
    if pos is None:
        pos = {root: (xcenter, vert_loc)}
    else:
        pos[root] = (xcenter, vert_loc)
    children = list(G.successors(root))
    if len(children) != 0 :
        #x+=1
        dx = width / len(children)
        nextx = xcenter - width/2 - dx/2
        for child in children:
            nextx += dx
            pos = hierarchy_pos(G, child, width=dx, vert_gap=vert_gap,
                                vert_loc=vert_loc-vert_gap, xcenter=nextx, pos=pos, parent=root)
    return pos"""

# for larger trees
def hierarchy_pos(G, root, width=1.0, vert_gap=0.2, vert_loc=0, xcenter=0.5, pos=None, parent=None):
    """
    Recursive function to compute hierarchical layout of a tree/DAG.
    
    Parameters:
    - G: A NetworkX DiGraph (tree or DAG).
    - root: Root node of the hierarchy.
    - width: Total horizontal space allocated.
    - vert_gap: Gap between levels (vertical spacing).
    - vert_loc: Initial vertical location.
    - xcenter: Initial horizontal center position.
    - pos: (Used internally) dict of positions.
    - parent: (Used internally) the node’s parent to avoid backtracking.
    
    Returns:
    - pos: Dictionary {node: (x, y)} of positions.
    """
    if pos is None:
        pos = {root: (xcenter, vert_loc)}
    else:
        pos[root] = (xcenter, vert_loc)

    children = list(G.successors(root))
    if parent is not None and parent in children:
        children.remove(parent)  # Avoid cycles if accidentally present

    if len(children) != 0:
        dx = width / len(children)
        next_x = xcenter - width / 2 - dx / 2
        for child in children:
            next_x += dx
            pos = hierarchy_pos(
                G, child, width=dx, vert_gap=vert_gap,
                vert_loc=vert_loc - vert_gap, xcenter=next_x,
                pos=pos, parent=root
            )
    return pos


# -------------------------------
# TreeCanvas Using NetworkX & Matplotlib


class TreeCanvas(QWidget): # To show the tree inside the GUI widget 
    """
    Custom widget to display an AVL tree or awards list diagram.
    Uses NetworkX to build the graph structure and Matplotlib to draw it.
    Draws into a QPixmap and paints onto this QWidget.
    """

    def __init__(self, parent=None):
        # Call Qt constructor to set up the widget
        super(TreeCanvas, self).__init__(parent)
        # This will hold our input data (either a tree or a list of nodes)
        self.data = None
        # Ensure the widget is tall enough to show the diagram
        self.setMinimumHeight(300)
        # Simple white background with a light gray border
        self.setStyleSheet(
            "background-color: white;"
            " border: 2px solid #e0e0e0;"
            " border-radius: 10px;"
        )

    def setData(self, data):
        """
        Setter for the data to draw.
        data should be a dict with keys:
          - 'mode': 'full' or 'award'
          - 'root': the root node (for full tree)
          - 'nodes': list of nodes (for award view)
        After setting, trigger a repaint of the widget.
        """
        self.data = data
        # Tell Qt that the widget needs to be redrawn
        self.update()

    def build_graph(self, node, G):
        """
        Helper to build a NetworkX directed graph from an AVL tree.
        Recursively adds nodes and edges for left/right children.
        """
        if node is None:
            return
        # Create a label combining student name and GPA
        label = f"{node.name}\n{node.current_gpa}"
        G.add_node(node.name, label=label)
        # If there is a left child, draw an edge and recurse
        if node.left:
            G.add_edge(node.name, node.left.name)
            self.build_graph(node.left, G)
        # If there is a right child, draw an edge and recurse
        if node.right:
            G.add_edge(node.name, node.right.name)
            self.build_graph(node.right, G)

    def build_award_graph(self, nodes, G):
        """
        Helper to build a flat graph for awardees list.
        No edges—just one node per student.
        """
        for node in nodes:
            label = f"{node.name}\n{node.current_gpa}"
            G.add_node(node.name, label=label)

    def paintEvent(self, event): # Whenever there is new data or resizing this function is called
        """
        Qt calls this method whenever the widget needs repainting.
        We read self.data, build the proper graph, draw it to an image,
        then paint that image onto this widget.
        """
        # If no data provided, nothing to draw
        if not self.data:
            return

        mode = self.data.get("mode")
        # Create an empty directed graph
        G = nx.DiGraph()

        if mode == "full":
            # Full tree view: expect a 'root' in data
            root = self.data.get("root")
            if not root:
                return
            # Recursively add nodes/edges
            self.build_graph(root, G)
            # Compute positions in a hierarchical layout
            pos = hierarchy_pos(G, root.name)

        elif mode == "award":
            # Awards view: expect a list of nodes
            nodes = self.data.get("nodes", [])
            if not nodes:
                return
            # Add nodes only
            self.build_award_graph(nodes, G)
            # Arrange nodes in a horizontal line
            pos = {}
            n = len(nodes)
            for i, node in enumerate(nodes):
                # Spread evenly between 0 and 1 on x-axis, y fixed at 0.5
                pos[node.name] = ((i + 1) / (n + 1), 0.5)
        else:
            # Unknown mode: do nothing
            return

        # Prepare a Matplotlib figure matching widget size
        plt.figure(figsize=(self.width()/100, self.height()/100))
        labels = nx.get_node_attributes(G, 'label')
        # Draw nodes and edges with simple styling
        if mode == "full":
            nx.draw(
                G, pos, labels=labels, with_labels=True,
                node_size=1500, node_color='#80b3ff', edge_color='#003366',
                font_size=10, font_weight='bold'
            )
        else:
            nx.draw(
                G, pos, labels=labels, with_labels=True,
                node_size=1500, node_color='#ffcc80', edge_color='#cc6600',
                font_size=10, font_weight='bold'
            )

        # Save plot to an in-memory buffer
        buf = io.BytesIO()
        plt.savefig(buf, format='png', bbox_inches='tight')
        plt.close()
        buf.seek(0)

        # Load image data into Qt objects
        img = QImage()
        img.loadFromData(buf.getvalue())
        pixmap = QPixmap.fromImage(img)

        # Paint the pixmap onto this widget
        painter = QPainter(self)
        painter.drawPixmap(0, 0, self.width(), self.height(), pixmap)
        
# -------------------------------
# PyQt5 GUI 

class GPA_GUI(QMainWindow):
    def __init__(self):
        super().__init__()
        # Set main window title and size
        self.setWindowTitle("🌟 University GPA Leaderboard & Awards")
        self.setGeometry(100, 100, 1000, 800)
        # Apply a light background and font family to the whole app
        self.setStyleSheet("background-color: #f4f6f9; font-family: 'Segoe UI';")

        # Data structures for AVL tree and student records
        self.tree_data = AVLTree()        # AVLTree instance for GPA rankings
        self.avl_root = None              # Root node of the AVL tree
        self.students = []                # List of (name, previous_gpa, current_gpa)
        self.csv_path = None              

        # Central widget and main vertical layout
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        self.main_layout = QVBoxLayout()
        central_widget.setLayout(self.main_layout)

        # Top panel control
        self.create_controls()            # Load data, award selector, refresh
        self.create_modification_controls()  # Buttons to add/remove students
        self.create_gpa_update_controls()    # Inputs to update a student's GPA

        # Canvas to visualize the AVL tree structure
        self.tree_canvas = TreeCanvas()
        self.tree_canvas.setFixedHeight(300)
        self.main_layout.addWidget(
            self.create_card(self.tree_canvas, "AVL Tree Visualization")
        )

        # Text area for outputting leaderboard and awards information
        self.text_area = QTextEdit()
        self.text_area.setReadOnly(True)
        self.text_area.setFont(QFont("Segoe UI", 10))
        self.text_area.setStyleSheet("border: none; background-color: white;")
        self.main_layout.addWidget(
            self.create_card(self.text_area, "Leaderboard Output")
        )

    def create_controls(self):
        # Layout for the top row of buttons and award selector
        layout = QHBoxLayout()
        layout.setSpacing(15)

        def styled_button(text):
            # Helper to create a uniformly styled button
            btn = QPushButton(text)
            btn.setCursor(Qt.PointingHandCursor)
            btn.setStyleSheet(
                """
                QPushButton {
                    background-color: #4da6ff;
                    color: white;
                    border-radius: 10px;
                    padding: 10px 20px;
                    font-weight: bold;
                }
                QPushButton:hover {
                    background-color: #3399ff;
                }
                """
            )
            return btn

        # Button to load built-in sample dataset
        self.load_sample_btn = styled_button("📋 Load Sample Data")
        self.load_sample_btn.clicked.connect(self.load_sample_data)
        layout.addWidget(self.load_sample_btn)

        # Button to load from a CSV file
        self.load_csv_btn = styled_button("📁 Load CSV")
        self.load_csv_btn.clicked.connect(self.load_csv_data) #Button clicked for csv load
        layout.addWidget(self.load_csv_btn)

        # Label and dropdown to pick which award to display
        label = QLabel("🏆 Award:")
        label.setStyleSheet("font-weight: bold;")
        layout.addWidget(label)

        self.award_combo = QComboBox()
        self.award_combo.addItems([
            "Full Leaderboard", "Dean's List", "President's List", "High Leap Award"
        ])
        self.award_combo.currentIndexChanged.connect(self.update_display_for_award)
        self.award_combo.setStyleSheet(
            """
            QComboBox {
                background-color: white;
                padding: 5px 10px;
                border: 1px solid #ccc;
                border-radius: 8px;
            }
            """
        )
        layout.addWidget(self.award_combo)

        # Refresh button to re-read the CSV and rebuild tree
        self.refresh_btn = styled_button("🔄 Refresh")
        self.refresh_btn.clicked.connect(self.refresh_csv) #refresh csv button clicked
        layout.addWidget(self.refresh_btn)

        # Wrap the controls in a styled card/frame
        frame = self.create_card_layout(layout)
        self.main_layout.addWidget(frame)

    def create_modification_controls(self):
        # Controls for inserting and deleting student records 
        #UI , Buttons with their respective names
        mod_layout = QVBoxLayout()
        mod_layout.setSpacing(10)

        # - Insert controls: name, previous GPA, current GPA, and button 
        insert_layout = QHBoxLayout()
        insert_layout.setSpacing(10)
        # Text field for student name
        self.insert_name = QLineEdit()
        self.insert_name.setPlaceholderText("Name")
        # Text field for previous semester GPA
        self.insert_prev = QLineEdit()
        self.insert_prev.setPlaceholderText("Previous GPA")
        # Text field for current semester GPA
        self.insert_curr = QLineEdit()
        self.insert_curr.setPlaceholderText("Current GPA")
        # Button to trigger insertion
        insert_btn = QPushButton("Insert Record")
        insert_btn.setCursor(Qt.PointingHandCursor)
        insert_btn.setStyleSheet(
            "background-color: #28a745; color: white; border-radius: 10px; padding: 8px 16px;"
        )
        insert_btn.clicked.connect(self.insert_record) # insert record button clicked
        # Add widgets to the horizontal insert layout
        insert_layout.addWidget(QLabel("Insert:"))
        insert_layout.addWidget(self.insert_name)
        insert_layout.addWidget(self.insert_prev)
        insert_layout.addWidget(self.insert_curr)
        insert_layout.addWidget(insert_btn)

        # --- Delete controls: name and button ---
        delete_layout = QHBoxLayout()
        delete_layout.setSpacing(10)
        # Text field for specifying which student to delete
        self.delete_name = QLineEdit()
        self.delete_name.setPlaceholderText("Name to Delete")
        # Button to trigger deletion
        delete_btn = QPushButton("Delete Record")
        delete_btn.setCursor(Qt.PointingHandCursor)
        delete_btn.setStyleSheet(
            "background-color: #dc3545; color: white; border-radius: 10px; padding: 8px 16px;"
        )
        delete_btn.clicked.connect(self.delete_record) #delete button clicked
        # Add widgets to the horizontal delete layout
        delete_layout.addWidget(QLabel("Delete:"))
        delete_layout.addWidget(self.delete_name)
        delete_layout.addWidget(delete_btn)

        # Combine insert and delete layouts vertically
        mod_layout.addLayout(insert_layout)
        mod_layout.addLayout(delete_layout)

        # Wrap in a styled card and add to the main layout
        frame = self.create_card_layout(mod_layout)
        self.main_layout.addWidget(frame)

    def create_gpa_update_controls(self):
        layout = QHBoxLayout()
        layout.setSpacing(10)

        self.update_name = QLineEdit()
        self.update_name.setPlaceholderText("Student Name")
        self.update_old_gpa_input = QLineEdit()
        self.update_old_gpa_input.setPlaceholderText("Old GPA")
        self.update_gpa_input = QLineEdit()
        self.update_gpa_input.setPlaceholderText("New GPA")

        btn_upd = QPushButton("Update GPA")
        btn_upd.setCursor(Qt.PointingHandCursor)
        btn_upd.setStyleSheet(
            "background-color: #ff9900; color: white; border-radius: 10px; padding: 8px 16px;"
        )
        btn_upd.clicked.connect(self.update_gpa)

        layout.addWidget(QLabel("Update GPA:"))
        layout.addWidget(self.update_name)
        layout.addWidget(self.update_old_gpa_input)
        layout.addWidget(self.update_gpa_input)
        layout.addWidget(btn_upd)

        self.main_layout.addWidget(self.create_card_layout(layout))
    def update_gpa(self):
        """
        O(log n) update: look up by (name, old_gpa) in AVL, delete old node, then re-insert with new_gpa.
        """
        name = self.update_name.text().strip()
        try:
            old_gpa = float(self.update_old_gpa_input.text().strip())
            new_gpa = float(self.update_gpa_input.text().strip())
        except ValueError:
            QMessageBox.warning(self, "Warning", "Please enter valid GPA values.")
            return

        if not name or not (0.0 <= old_gpa <= 4.0 and 0.0 <= new_gpa <= 4.0):
            QMessageBox.warning(self, "Warning", "Name must be nonempty and GPAs between 0 and 4.")
            return

        # 1) Locate the node in the AVL by (old_gpa, name)
        node = self.tree_data.find_node(self.avl_root, old_gpa, name)
        if node is None:
            QMessageBox.warning(self, "Warning", f"No record found for {name} with GPA {old_gpa}.")
            return

        # 2) Grab the previous_gpa stored in that node
        prev_gpa = node.previous_gpa

        # 3) Delete the old node (keyed by old_gpa), then insert new node
        self.avl_root = self.tree_data.delete(self.avl_root, old_gpa)
        self.avl_root = self.tree_data.insert(
            self.avl_root,
            name,
            new_gpa,
            prev_gpa
        )

        # 4) Sync the `students` list
        self.students = [
            (nm, pr, new_gpa) if nm.lower() == name.lower() and cu == old_gpa
            else (nm, pr, cu)
            for nm, pr, cu in self.students
        ]

        # 5) Refresh the display
        self.update_display_for_award()
        self.display_message(f"✅ Updated {name}: {old_gpa} → {new_gpa}\n")

        # 6) Clear input fields
        self.update_name.clear()
        self.update_old_gpa_input.clear()
        self.update_gpa_input.clear()



    def create_card_layout(self, layout):
        # ====== Wrap any layout inside a styled card frame ======
        card = QFrame()
        card.setLayout(layout)
        card.setStyleSheet("""
            QFrame {
                background-color: white;
                border-radius: 15px;
                padding: 15px;
                border: 1px solid #ddd;
            }
        """)
        return card


    def create_card(self, widget, title=""):
        # Wrap a widget in a styled card with an optional title label
        card_layout = QVBoxLayout()
        if title:
            title_label = QLabel(title)
            title_label.setStyleSheet(
                "font-weight: bold; font-size: 16px; padding-bottom: 5px;"
            )
            card_layout.addWidget(title_label)
        card_layout.addWidget(widget)

        container = QFrame()
        container.setLayout(card_layout)
        container.setStyleSheet(
            """
            QFrame {
                background-color: white;
                border: 1px solid #ccc;
                border-radius: 15px;
                padding: 10px;
            }
            """
        )
        return container

    def load_sample_data(self):
        # Load hardcoded sample students 
        self.students = [
            ("Ali", 4.0, 4.0), ("Aisha", 3.8, 3.9), ("pop", 2.0, 3.0),
            ("Bilal", 2.9, 1.2), ("Sara", 3.7, 3.4), ("Usman", 3.0, 3.5),
            ("Zoya", 3.9, 3.1), ("Ahmed", 3.1, 3.1), ("Fatima", 3.6, 3.9),
            ("sal", 4.0, 3.8), ("kol", 3.0, 1.9), ("salman", 4.0, 2.82),
            ("Hassan", 3.4, 2.66), ("Aminah", 3.8, 3.77), ("add", 3.2, 2.6),
            ("sub", 2.7, 3.3)
        ]
        # Clear any previously loaded CSV
        self.csv_path = None
        # Rebuild and display
        self.build_tree()
        self.update_display_for_award()
        self.display_message("✅ Sample data loaded successfully.\n")

    def load_csv_data(self):
        # Prompt user to select a CSV file, then parse it
        filename, _ = QFileDialog.getOpenFileName(
            self, "Select CSV File", "", "CSV Files (*.csv)"
        )
        if not filename:
            return  # User canceled
        self.csv_path = filename
        self.students.clear()
        try:
            with open(filename, newline='') as csvfile:
                reader = csv.DictReader(csvfile)
                for row in reader:
                    name = row['name'].strip()
                    prev = float(row['previous_gpa'].strip())
                    curr = float(row['current_gpa'].strip())
                    # Only accept valid GPA ranges
                    if 0 <= prev <= 4.0 and 0 <= curr <= 4.0:
                        self.students.append((name, prev, curr))
                    else:
                        self.display_message(
                            f"⚠️ Invalid GPA for {name}. Skipped.\n"
                        )
            # Rebuild and display
            self.build_tree()
            self.update_display_for_award()
            self.display_message("✅ CSV data loaded successfully.\n")
        except Exception as e:
            QMessageBox.critical(self, "Error", str(e))

    def refresh_csv(self):
        # Reload the original CSV file, if one was loaded
        if self.csv_path:
            self.load_csv_data()
        else:
            self.display_message("❗ No CSV file loaded to refresh.\n")

    def write_csv(self):
        # Save current `self.students` back to disk if a CSV is loaded
        if not self.csv_path:
            QMessageBox.warning(
                self, "Warning",
                "No CSV file loaded. Please load a CSV file first."
            )
            return
        try:
            with open(self.csv_path, 'w', newline='') as csvfile:
                fieldnames = ['name', 'previous_gpa', 'current_gpa']
                writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
                writer.writeheader()
                for name, prev, curr in self.students:
                    writer.writerow({
                        'name': name,
                        'previous_gpa': prev,
                        'current_gpa': curr
                    })
        except Exception as e:
            QMessageBox.critical(
                self, "Error", f"Failed to write CSV: {e}"
            )

    def insert_record(self): # insert function
        # Read input fields for new student
        name = self.insert_name.text().strip()
        try:
            prev = float(self.insert_prev.text().strip())
            curr = float(self.insert_curr.text().strip())
        except ValueError:
            QMessageBox.warning(self, "Warning", "Please enter valid GPA values.")
            return
        if not name:
            QMessageBox.warning(self, "Warning", "Please enter a name.")
            return
        if not (0 <= prev <= 4.0 and 0 <= curr <= 4.0):
            QMessageBox.warning(
                self, "Warning",
                "GPA values must be between 0 and 4."
            )
            return
        # Add to list and save
        self.students.append((name, prev, curr))
        self.write_csv()
        # Rebuild and refresh UI
        self.build_tree()
        self.update_display_for_award()
        self.display_message(f"✅ Record inserted for {name}.\n")
        # Clear input fields
        self.insert_name.clear()
        self.insert_prev.clear()
        self.insert_curr.clear()

    def delete_record(self): # delete function
        # Read the student name to delete
        name = self.delete_name.text().strip()
        if not name:
            QMessageBox.warning(
                self, "Warning",
                "Please enter a name to delete."
            )
            return
        # Filter out matching records (case-insensitive)
        new_list = [s for s in self.students if s[0].lower() != name.lower()]
        if len(new_list) == len(self.students):
            QMessageBox.information(
                self, "Info",
                f"No record found for {name}."
            )
            return
        self.students = new_list
        self.write_csv()
        self.build_tree()
        self.update_display_for_award()
        self.display_message(f"✅ Record(s) deleted for {name}.\n")
        self.delete_name.clear()

    def build_tree(self):
        # Rebuild the AVL tree from self.students list
        self.avl_root = None
        for name, prev, curr in self.students:
            self.avl_root = self.tree_data.insert( # calling original insert function 
                self.avl_root, name, curr, prev
            )

    def update_display_for_award(self):
        # Determine which award view is selected and update both tree_canvas and text_area
        award = self.award_combo.currentText()
        output = ""
        if award == "Full Leaderboard":
            nodes = self.tree_data.inorder_traversal(self.avl_root)
            self.tree_canvas.setData({"mode": "full", "root": self.avl_root})
            output += "🏅 Full GPA Leaderboard:\n"
            for idx, node in enumerate(nodes, 1):
                output += (
                    f"{idx}. {node.name} - GPA: {node.current_gpa}, "
                    f"Prev: {node.previous_gpa}\n"
                )
        elif award == "Dean's List":
            nodes = get_deans_list(self.tree_data, self.avl_root)
            self.tree_canvas.setData({"mode": "award", "nodes": nodes})
            output += "🎓 Dean's List (Top 5%):\n"
            for idx, node in enumerate(nodes, 1):
                output += f"{idx}. {node.name} - GPA: {node.current_gpa}\n"
        elif award == "President's List":
            nodes = get_presidents_list(self.tree_data, self.avl_root)
            self.tree_canvas.setData({"mode": "award", "nodes": nodes})
            output += "🏅 President's List (Two Semesters):\n"
            for idx, node in enumerate(nodes, 1):
                output += (
                    f"{idx}. {node.name} - GPA: {node.current_gpa}, "
                    f"Prev: {node.previous_gpa}\n"
                )
        elif award == "High Leap Award":
            nodes = get_high_leap_award(self.tree_data, self.avl_root)
            self.tree_canvas.setData({"mode": "award", "nodes": nodes})
            output += "🚀 High Leap Award (≥ 0.5 GPA increase):\n"
            for idx, node in enumerate(nodes, 1):
                inc = node.current_gpa - node.previous_gpa
                output += (
                    f"{idx}. {node.name} - GPA: {node.current_gpa}, "
                    f"Prev: {node.previous_gpa} (⬆ {inc:.2f})\n"
                )
        else:
            output = "❓ Unknown Award Selected."
        # Display the compiled output in the text area
        self.display_message(output)

    def display_message(self, msg):
        # Replace the text area contents with the provided message
        self.text_area.setPlainText(msg)


def main():
    app = QApplication(sys.argv)
    gui = GPA_GUI()
    gui.show()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
