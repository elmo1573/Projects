# DNA to mRNA conversion
def DNA_MRNA(inputDNA):
    MRNA = ''
    inputDNA = inputDNA.upper()
    for code in inputDNA:
        if code == 'A':
            MRNA += 'U'
        elif code == 'C':
            MRNA += 'G'
        elif code == 'T':
            MRNA += 'A'
        elif code == 'G':
            MRNA += 'C'
    return MRNA


# Calculate similarity score
def similarity_score(similar, lst1, lst2):
    return len(similar) / (len(lst1) + len(lst2))

# Get similar palindromes
def similar_palindromes(lst1, lst2):
    similar = ''
    for i in lst1:
        if i in lst2:
            similar += i
    return similar


