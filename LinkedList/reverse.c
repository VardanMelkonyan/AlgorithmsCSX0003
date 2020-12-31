struct Node {
	int val;
	struct Node *next;
};

// a -> b -> c -> d
// d -> c -> b -> a

struct Node reverseLikedList(struct Node *linkedList) {
	struct Node *node = head;
	struct Node *previous = NULL;
	struct Node *nextGuy;

	if (!node) return (node);

	while (node->next) {
		//b | c
		nextGuy = node->next;
		//NULL | a
		node->next = previous;
		//a | b
		previous = node;
		//b | c
		node = nextGuy;
	}
	node->next = previous;
	return(node);
}
