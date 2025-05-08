import tkinter as tk
from tkinter import messagebox


def needleman_wunsch(seq1, seq2):
    match_score = 1
    mismatch_penalty = -1
    gap_penalty = -1


    # Initialize the score matrix
    rows = len(seq1) + 1
    cols = len(seq2) + 1
    score_matrix = [[0] * cols for _ in range(rows)]
    traceback_matrix = [[0] * cols for _ in range(rows)]
    
    # Fill the first row and column with gap penalties
    for i in range(1, rows):
        score_matrix[i][0] = score_matrix[i-1][0] + gap_penalty
        traceback_matrix[i][0] = "up"  # Indicates a gap in seq2


    for j in range(1, cols):
        score_matrix[0][j] = score_matrix[0][j-1] + gap_penalty
        traceback_matrix[0][j] = "left"  # Indicates a gap in seq1


    # Fill in the rest of the matrix
    for i in range(1, rows):
        for j in range(1, cols):
            match = score_matrix[i-1][j-1] + (match_score if seq1[i-1] == seq2[j-1] else mismatch_penalty)
            delete = score_matrix[i-1][j] + gap_penalty
            insert = score_matrix[i][j-1] + gap_penalty
            score_matrix[i][j] = max(match, delete, insert)
            
            # Update traceback matrix
            if score_matrix[i][j] == match:
                traceback_matrix[i][j] = "diag"  # Indicates a match/mismatch
            elif score_matrix[i][j] == delete:
                traceback_matrix[i][j] = "up"  # Indicates a gap in seq2
            else:
                traceback_matrix[i][j] = "left"  # Indicates a gap in seq1


    return score_matrix, traceback_matrix


def traceback(score_matrix, traceback_matrix, seq1, seq2):
    alignment_seq1 = ""
    alignment_seq2 = ""
    i, j = len(seq1), len(seq2)
    
    while i > 0 or j > 0:
        if i > 0 and j > 0 and traceback_matrix[i][j] == "diag":
            alignment_seq1 = seq1[i-1] + alignment_seq1
            alignment_seq2 = seq2[j-1] + alignment_seq2
            i -= 1
            j -= 1
        elif i > 0 and traceback_matrix[i][j] == "up":
            alignment_seq1 = seq1[i-1] + alignment_seq1
            alignment_seq2 = "-" + alignment_seq2
            i -= 1
        else:
            alignment_seq1 = "-" + alignment_seq1
            alignment_seq2 = seq2[j-1] + alignment_seq2
            j -= 1
    
    return alignment_seq1, alignment_seq2




# function to validate the DNA sequence entered
def is_valid_dna(sequence):
    valid_bases = {'A', 'T', 'C', 'G','a','t','c','g'}
    return all(base in valid_bases for base in sequence)


def run_alignment():
    seq1 = seq1_entry.get()
    seq2 = seq2_entry.get()




    if not is_valid_dna(seq1) or not is_valid_dna(seq2):
        messagebox.showerror("Error", "Invalid DNA sequence! Only A, T, C, and G characters are allowed.")
        return


    score_matrix, traceback_matrix = needleman_wunsch(seq1, seq2)
    alignment_seq1, alignment_seq2 = traceback(score_matrix, traceback_matrix, seq1, seq2)
    alignment_score = score_matrix[-1][-1]  # Final score
    
    alignment_text.delete(1.0, tk.END)
    alignment_text.insert(tk.END, "Alignment Score: " + str(alignment_score) + "\n\n")
    alignment_text.insert(tk.END, "Alignment:\n")
    alignment_text.insert(tk.END, alignment_seq1 + "\n")
    alignment_text.insert(tk.END, alignment_seq2 + "\n")


# Create GUI
root = tk.Tk()
root.title("Needleman-Wunsch Alignment")
root.geometry("1500x600")  # Set window size to 1500x600


# Labels and entries for input sequences
tk.Label(root, text="Sequence 1:").grid(row=0, column=0)
seq1_entry = tk.Entry(root, width=100)
seq1_entry.grid(row=0, column=1)


tk.Label(root, text="Sequence 2:").grid(row=1, column=0)
seq2_entry = tk.Entry(root, width=100)
seq2_entry.grid(row=1, column=1)


# Button to run alignment
align_button = tk.Button(root, text="Run Alignment", command=run_alignment, width=20)
align_button.grid(row=2, columnspan=2, pady=10)


# Text widget to display alignment results
alignment_text = tk.Text(root, width=120, height=20)
alignment_text.grid(row=3, columnspan=2)


root.mainloop()