import tkinter as tk
from tkinter import ttk
from tkinter import messagebox

def smith_waterman(seq1, seq2, match=2, mismatch=-1, gap_penalty=-1):
    # Initialize the scoring matrix and traceback matrix
    rows = len(seq1) + 1
    cols = len(seq2) + 1
    score_matrix = [[0] * cols for _ in range(rows)]
    traceback_matrix = [[0] * cols for _ in range(rows)]

    # Initialize maximum score and its position
    max_score = 0
    max_pos = (0, 0)

    # Fill the scoring matrix
    for i in range(1, rows):
        for j in range(1, cols):
            if seq1[i - 1] == seq2[j - 1]:
                match_score = score_matrix[i - 1][j - 1] + match
            else:
                match_score = score_matrix[i - 1][j - 1] + mismatch

            gap_in_seq1 = score_matrix[i - 1][j] + gap_penalty
            gap_in_seq2 = score_matrix[i][j - 1] + gap_penalty

            # Choose the maximum score among match/mismatch and gap penalties
            score_matrix[i][j] = max(0, match_score, gap_in_seq1, gap_in_seq2)

            # Update traceback matrix
            if score_matrix[i][j] == 0:
                traceback_matrix[i][j] = 0
            elif score_matrix[i][j] == gap_in_seq1:
                traceback_matrix[i][j] = 1
            elif score_matrix[i][j] == gap_in_seq2:
                traceback_matrix[i][j] = 2
            else:
                traceback_matrix[i][j] = 3

            # Update maximum score and its position
            if score_matrix[i][j] > max_score:
                max_score = score_matrix[i][j]
                max_pos = (i, j)

    # Traceback to find the aligned sequences
    aligned_seq1 = ""
    aligned_seq2 = ""
    i, j = max_pos
    while i > 0 and j > 0 and score_matrix[i][j] > 0:
        if traceback_matrix[i][j] == 0:
            break
        elif traceback_matrix[i][j] == 1:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = "-" + aligned_seq2
            i -= 1
        elif traceback_matrix[i][j] == 2:
            aligned_seq1 = "-" + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            j -= 1
        else:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            i -= 1
            j -= 1

    return max_score, aligned_seq1, aligned_seq2

def is_valid_dna(sequence):
    valid_bases = {'A', 'T', 'C', 'G', 'a', 't', 'c', 'g'}
    return all(base in valid_bases for base in sequence)

def align_sequences():
    seq1 = seq1_entry.get()
    seq2 = seq2_entry.get()

    if not is_valid_dna(seq1) or not is_valid_dna(seq2):
        messagebox.showerror("Error", "Invalid DNA sequence! Only A, T, C, and G characters are allowed.")
        return

    score, aligned_seq1, aligned_seq2 = smith_waterman(seq1, seq2)
    score_label.config(text="Alignment Score: " + str(score))
    aligned_seq1_text.config(state="normal")
    aligned_seq1_text.delete("1.0", tk.END)
    aligned_seq1_text.insert("1.0", aligned_seq1)
    aligned_seq1_text.config(state="disabled")
    aligned_seq2_text.config(state="normal")
    aligned_seq2_text.delete("1.0", tk.END)
    aligned_seq2_text.insert("1.0", aligned_seq2)
    aligned_seq2_text.config(state="disabled")

# Create the main window
root = tk.Tk()
root.title("Sequence Alignment")
root.geometry("1000x600")  # Set window size to 1000x600

# Create input fields for sequences
seq1_label = ttk.Label(root, text="Sequence 1:")
seq1_label.grid(row=0, column=0, padx=5, pady=5, sticky="e")
seq1_entry = tk.Entry(root, width=100)
seq1_entry.grid(row=0, column=1, padx=5, pady=5)

seq2_label = ttk.Label(root, text="Sequence 2:")
seq2_label.grid(row=1, column=0, padx=5, pady=5, sticky="e")
seq2_entry = ttk.Entry(root, width=100)
seq2_entry.grid(row=1, column=1, padx=5, pady=5)

# Button to trigger sequence alignment
align_button = ttk.Button(root, text="Align Sequences", command=align_sequences)
align_button.grid(row=2, column=0, columnspan=2, padx=5, pady=5)

# Labels to display alignment score and aligned sequences
score_label = ttk.Label(root, text="Alignment Score:")
score_label.grid(row=3, column=0, columnspan=2, padx=5, pady=5)

aligned_seq1_label = ttk.Label(root, text="Aligned Sequence 1:")
aligned_seq1_label.grid(row=4, column=0, padx=5, pady=5)
aligned_seq1_text = tk.Text(root, width=50, height=10, state="disabled")
aligned_seq1_text.grid(row=4, column=1, padx=5, pady=5)

aligned_seq2_label = ttk.Label(root, text="Aligned Sequence 2:")
aligned_seq2_label.grid(row=5, column=0, padx=5, pady=5)
aligned_seq2_text = tk.Text(root, width=50, height=10, state="disabled")
aligned_seq2_text.grid(row=5, column=1, padx=5, pady=5)

root.mainloop()
