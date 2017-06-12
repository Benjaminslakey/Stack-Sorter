NUMBERS=$(python -c 'a = list(range(-100, 400)); a = [str(v) for v in a]; import random; random.shuffle(a); print " ".join(a)') && ./push_swap $NUMBERS
