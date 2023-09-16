def solution(N, A, B):
    # Create a dictionary to store the degree of each vertex
    degrees = {i: 0 for i in range(N)}

    # Calculate the degree of each vertex
    for a, b in zip(A, B):
        degrees[a] += 1
        degrees[b] += 1

    seconds = 0

    while True:
        # Count the vertices to be removed in this second
        to_remove = []

        for vertex, degree in degrees.items():
            if degree <= 1:
                to_remove.append(vertex)

        # If no vertices to remove, the process is complete
        if not to_remove:
            break

        # Update degrees and remove edges
        for vertex in to_remove:
            del degrees[vertex]

            for i in range(len(A)):
                if A[i] == vertex:
                    if B[i] in degrees:
                        degrees[B[i]] -= 1
                elif B[i] == vertex:
                    if A[i] in degrees:
                        degrees[A[i]] -= 1

        seconds += 1

    return seconds
    pass
