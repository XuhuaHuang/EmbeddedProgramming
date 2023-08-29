# Flatten Binary Tree to Linked List

- If there is no left node -> move to next right node.
- If `node->left != nullptr`
  - Store the right subtree
  - Add left subtree to right of root,
  - Now add the stored right subtree to the rightmost node of current tree.
- Make sure `node->left = nullptr`.
