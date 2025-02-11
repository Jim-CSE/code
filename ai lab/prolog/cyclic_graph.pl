% Define the edges of the graph
edge(a, b).
edge(a, c).
edge(b, d).
edge(d, e).
edge(e, b).

% Define the path predicate that finds a path from vertex A to vertex B
path(A, B) :-
    nextRoute(A, B, []),
    write(B).

% nextRoute explores the graph recursively while avoiding cycles
nextRoute(A, B, Visited) :-
    edge(A, X),           % Find an edge from A to another vertex X
    write(A), write(' -> '),
    not(member(X, Visited)),  % Ensure X has not been visited before
    (
        B = X;                % If X is the target vertex, stop
        nextRoute(X, B, [A | Visited])  % Otherwise, continue from X
    ).
