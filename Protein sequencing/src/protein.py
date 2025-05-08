import tkinter as tk
from tkinter import ttk

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_protein_tree(protein_sequence):
    if not protein_sequence:
        return None
    mid = len(protein_sequence) // 2
    root = TreeNode(protein_sequence[mid])
    root.left = build_protein_tree(protein_sequence[:mid])
    root.right = build_protein_tree(protein_sequence[mid+1:])
    return root

# Function to translate DNA to RNA
def DNA_TRNA(inputDNA):
    inputDNA = inputDNA.upper()
    TRNA = ''
    for code in inputDNA:
        if code == 'T':
            TRNA += 'U'
        else:
            TRNA += code
    return TRNA

# Function to translate DNA sequence to protein sequence
def translate_to_protein(dna_sequence):
    rna_sequence = DNA_TRNA(dna_sequence)

    # Codon table for translation
    codon_table = {
        'UUU': 'F', 'UUC': 'F', 'UUA': 'L', 'UUG': 'L',
        'CUU': 'L', 'CUC': 'L', 'CUA': 'L', 'CUG': 'L',
        'AUU': 'I', 'AUC': 'I', 'AUA': 'I', 'AUG': 'M',
        'GUU': 'V', 'GUC': 'V', 'GUA': 'V', 'GUG': 'V',
        'UCU': 'S', 'UCC': 'S', 'UCA': 'S', 'UCG': 'S',
        'CCU': 'P', 'CCC': 'P', 'CCA': 'P', 'CCG': 'P',
        'ACU': 'T', 'ACC': 'T', 'ACA': 'T', 'ACG': 'T',
        'GCU': 'A', 'GCC': 'A', 'GCA': 'A', 'GCG': 'A',
        'UAU': 'Y', 'UAC': 'Y', 'UAA': '*', 'UAG': '*',
        'CAU': 'H', 'CAC': 'H', 'CAA': 'Q', 'CAG': 'Q',
        'AAU': 'N', 'AAC': 'N', 'AAA': 'K', 'AAG': 'K',
        'GAU': 'D', 'GAC': 'D', 'GAA': 'E', 'GAG': 'E',
        'UGU': 'C', 'UGC': 'C', 'UGA': '*', 'UGG': 'W',
        'CGU': 'R', 'CGC': 'R', 'CGA': 'R', 'CGG': 'R',
        'AGU': 'S', 'AGC': 'S', 'AGA': 'R', 'AGG': 'R',
        'GGU': 'G', 'GGC': 'G', 'GGA': 'G', 'GGG': 'G',
    }

    protein_seq = ''
    codon_positions = []
    
    # Translate RNA sequence into protein sequence
    for i in range(0, len(rna_sequence), 3):
        codon = rna_sequence[i:i + 3]
        if codon in codon_table:
            protein_seq += codon_table[codon]
            codon_positions.append(i)

    return protein_seq, codon_positions

# Function to detect a basic disease based on protein sequence
def detect_disease(protein_sequence):
    # Hypothetical disease detection based on a protein motif
    if 'GAATTCCTTAAG' in protein_sequence:
        return ('Recognition Sequence of Escherichia coli identified, EcoR1 enzyme ')
    elif 'ETAYSNHR' in protein_sequence:
        return ('Recognition Sequence of Bacillus amyloliquefaciens identified, BamH1 enzyme')
    elif 'MTEITAAMVKELRESTGAGMMDCKNALSETN'  in protein_sequence:
        return ('Recognition Sequence of Common Fever identified')
    elif 'CIRRKRK'  in protein_sequence:
        return ('Recognition Sequence of coccobacillus bacteria')
    else:
        return "No disease detected"

# Function to generate and display the tree of the protein sequence
def display_tree(node, canvas, x, y, x_offset, y_offset):
    if node is not None:
        canvas.create_oval(x - 10, y - 10, x + 10, y + 10, fill="white")
        canvas.create_text(x, y, text=node.data)
        if node.left is not None:
            canvas.create_line(x, y, x - x_offset, y + y_offset, arrow=tk.LAST)
            display_tree(node.left, canvas, x - x_offset, y + y_offset, x_offset/2, y_offset)
        if node.right is not None:
            canvas.create_line(x, y, x + x_offset, y + y_offset, arrow=tk.LAST)
            display_tree(node.right, canvas, x + x_offset, y + y_offset, x_offset/2, y_offset)

def highlight_protein_codons(rna_sequence, codon_positions):
    highlighted_sequence = list(rna_sequence)
    for pos in codon_positions:
        highlighted_sequence[pos:pos+3] = ['<', rna_sequence[pos:pos+3], '>']
    return ''.join(highlighted_sequence)

# Function to display the translated sequences and disease prediction
def display_sequence():
    
    
    filename = seq_filename_entry.get()

    # Read DNA sequence from file
    with open(filename, 'r') as file:
        dna_sequence = file.read().replace('\n', '').strip().upper()  # Remove newlines and convert to uppercase

    rna_sequence= DNA_TRNA(dna_sequence)
    # Translate DNA sequence into protein sequence
    
    protein_sequence, codon_positions = translate_to_protein(dna_sequence)


    # Display the protein sequence in the text widget
    protein_sequence_text.config(state="normal")
    protein_sequence_text.delete("1.0", tk.END)
    protein_sequence_text.insert("1.0", protein_sequence)
    protein_sequence_text.config(state="disabled")

# Translate DNA sequence into protein sequence and get codon positions
    protein_sequence, codon_positions = translate_to_protein(dna_sequence)
    protein_sequence_text.config(state="normal")
    protein_sequence_text.delete("1.0", tk.END)
    protein_sequence_text.insert("1.0", protein_sequence)
    protein_sequence_text.config(state="disabled")

    # Highlight protein codons in DNA sequence
    highlighted_dna_sequence = highlight_protein_codons(rna_sequence, codon_positions)
    highlighted_dna_sequence_text.config(state="normal")
    highlighted_dna_sequence_text.delete("1.0", tk.END)
    highlighted_dna_sequence_text.insert("1.0", highlighted_dna_sequence)
    highlighted_dna_sequence_text.config(state="disabled")

    # Detect disease based on the protein sequence
    disease_prediction = detect_disease(protein_sequence)

    # Display disease prediction in the GUI
    disease_label.config(text=f"Disease Prediction: {disease_prediction}")

    # Build and display the protein sequence tree
    root = build_protein_tree(protein_sequence)
    canvas.delete("all")
    display_tree(root, canvas, 250, 50, 100, 50)

# Create the main window
root = tk.Tk()
root.title("Protein Sequence Analysis and Disease Detection")

# Input field for sequence file name
seq_filename_label = ttk.Label(root, text="Sequence File Name:")
seq_filename_label.grid(row=0, column=0, padx=5, pady=5, sticky="e")
seq_filename_entry = ttk.Entry(root, width=30)
seq_filename_entry.grid(row=0, column=1, padx=5, pady=5)

# Button to trigger sequence analysis
display_button = ttk.Button(root, text="Display Sequence", command=display_sequence)
display_button.grid(row=0, column=2, padx=5, pady=5)

# Text widget to display protein sequence
protein_sequence_label = ttk.Label(root, text="Protein Sequence:")
protein_sequence_label.grid(row=1, column=0, padx=5, pady=5)
protein_sequence_text = tk.Text(root, width=50, height=5, state="disabled")
protein_sequence_text.grid(row=1, column=1, columnspan=2, padx=5, pady=5)

# Label to display disease prediction
disease_label = ttk.Label(root, text="Disease Prediction:")
disease_label.grid(row=2, column=0, padx=5, pady=5, sticky="e")

# Label to display Protein Codon
aligned_seq1_label = ttk.Label(root, text="Protein Codon:")
aligned_seq1_label.grid(row=3, column=0, padx=5, pady=5)

highlighted_dna_sequence_text = tk.Text(root, width=90, height=10, state="disabled")
highlighted_dna_sequence_text.grid(row=3, column=1, columnspan=3, padx=5, pady=5)

# Canvas to display the protein sequence tree
canvas_label = ttk.Label(root, text="Protein Tree:")
canvas = tk.Canvas(root, width=900, height=400, bg="white")
canvas.grid(row=4, column=0, columnspan=3, padx=5, pady=5)

root.mainloop()
