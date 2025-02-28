% Edge definition: edge(StartNode, EndNode, Cost).
edge(a, b, 1).
edge(a, c, 3).
edge(b, d, 1).
edge(b, e, 6).
edge(c, f, 2).
edge(d, g, 5).
edge(e, g, 2).
edge(f, g, 3).

% Heuristic function: h(Node, HeuristicCost).
% This is problem-specific and is an estimate of the cost from the current node to the goal.
h(a, 7).
h(b, 6).
h(c, 4).
h(d, 2).
h(e, 1).
h(f, 3).
h(g, 0).  % The goal node should have a heuristic value of 0.

% A* search algorithm
astar(Start, Goal, Path, Cost) :-
    astar_search([node(Start, 0, 0, [])], Goal, Path, Cost).

% astar_search(OpenList, Goal, Path, Cost).
astar_search([node(Goal , Cost, PathToGoal)|], Goal, Path, Cost) :-
    reverse([Goal|PathToGoal], Path).  % When goal is reached, build the path.

astar_search([node(Current, G, _, Path)|RestOpenList], Goal, FinalPath, FinalCost) :-
    findall(node(Next, GNext, FNext, [Current|Path]),
            (edge(Current, Next, StepCost),
             \+ member(Next, Path),  % Avoid cycles
             GNext is G + StepCost,
             h(Next, HNext),
             FNext is GNext + HNext),
            NextNodes),
    append(RestOpenList, NextNodes, NewOpenList),
    sort(3, @=<, NewOpenList, SortedOpenList),  % Sort by the F cost (F = G + H)
    astar_search(SortedOpenList, Goal, FinalPath, FinalCost).
