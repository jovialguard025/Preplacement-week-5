def simple_text_editor(operations):
    text = []
    history = []

    for op in operations:
        parts = op.split()
        cmd = parts[0]

        if cmd == '1':  # append
            history.append(''.join(text))
            text.extend(parts[1])
        elif cmd == '2':  # delete
            k = int(parts[1])
            history.append(''.join(text))
            text = text[:-k]
        elif cmd == '3':  # print
            k = int(parts[1])
            print(text[k - 1])
        elif cmd == '4':  # undo
            text = list(history.pop())

# Driver code
if __name__ == "__main__":
    Q = int(input())
    operations = [input().strip() for _ in range(Q)]
    simple_text_editor(operations)
