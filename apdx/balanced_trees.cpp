/*
AVL tree
    strictly balanced tree
        balance(n) = n.left.height - n.right.height
        -1 <= balance(n) <= 1
    If there is a imbalance, it fix in a different way for each case using rotations.
    case1: Zig Zig
    case2: Zig Zag
*/

/*
Red-Black tree
    loosely balanced tree
        the length of paths differ by no more than a factor of two.
    Properties
        Every node is either red or black
        Root is black
        Leaves(NUll nodes) are black
        Red node must have two black children --> adjacent parent&child cannot be red at the same time
        Every path from a node to its leaves must have the same number of black nodes
        Newly inserted node is going to be red at first
    If there is a red/black violation, fix them by changing the color or rotation.
*/
