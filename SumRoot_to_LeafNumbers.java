class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}
public class SumRootToLeafNumbers {
    public int sumNumbers(TreeNode root) {
        return sumNumbersHelper(root, 0);
    }
    private int sumNumbersHelper(TreeNode node, int currentSum) {
        if (node == null) {
            return 0;
        }
        // Update the current sum by concatenating the current node's value.
        currentSum = currentSum * 10 + node.val;

        // If the current node is a leaf, return the current sum.
        if (node.left == null && node.right == null) {
            return currentSum;
        }
        // Recursively calculate the sum for the left and right subtrees.
        int leftSum = sumNumbersHelper(node.left, currentSum);
        int rightSum = sumNumbersHelper(node.right, currentSum);

        // Return the sum of both subtrees.
        return leftSum + rightSum;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        SumRootToLeafNumbers solution = new SumRootToLeafNumbers();
        int sum = solution.sumNumbers(root);

        System.out.println("Sum of root-to-leaf numbers: " + sum);
    }
}
