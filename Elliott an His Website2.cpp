/*
    Time Complexity : O(N*|S|)
    Space Complexity : O(N*|S|)

    Where, |S| is the maximum length of the strings and N is the total number of strings.
*/

// Trie data Structure.
struct trie {

	// An integer to store the last number added to the end of string.
	int lastElement;

	// A boolean to store if the current char is an end point for any string.
	bool isLast;

	// Array of pointers to store all the next connected nodes to the current node.
	trie* next[36];
	trie() {
		lastElement = 0;
		isLast = false;
		for (int i = 0; i < 36; i++)
		{
			next[i] = (NULL);
		}
	}
};

bool isPresent(trie *database, string &check, int index)
{
	int position = 26 + check[index] - '0';

	// Check if the current index for the current string is present or not.
	if (database->next[position] != NULL)
	{
		if (index == check.length() - 1)
		{

			// If the current index is already end of the string than return true.
			if (database->next[position]->isLast == true)
			{
				return true;
			}

			// If the current index is last index and this is not the end of any string.
			return false;
		}
		else
		{
			return isPresent(database->next[position], check, index + 1);
		}
	}
	return false;
}

int addInteger(trie *database)
{
	int ret;
	for (int i = database->lastElement; i <= 200005; i++) {
		string check = to_string(i);

		// Check if the current index is used or not.
		if (!isPresent(database, check, 0)) {
			database->lastElement = i;
			ret = i;
			break;
		}
	}
	return ret;
}

int addInDatabase(trie *database, string &s, int index)
{

	// return -1 if you are at end of string.
	if (index == s.length()) {
		return -1;
	}
	int position = s[index] <= '9' ? 26 + s[index] - '0' : s[index] - 'a';
	if (database->next[position] == NULL) {

		// If the current position is not used add it to the database.
		database->next[position] = new trie();
		if (index == s.length() - 1) {
			database->next[position]->isLast = true;
			return -1;
		}
		else {

			// Move to the next index.
			return addInDatabase(database->next[position], s, index + 1);
		}
	}
	else {
		if (index == s.length() - 1) {
			if (database->next[position]->isLast == true) {
				int k = addInteger(database->next[position]);
				string pass = to_string(k);

				// Push the new Username into the database.
				addInDatabase(database->next[position], pass, 0);
				return k;
			}

			// If it is the last index, update the value of isLast for the current node.
			database->next[position]->isLast = true;
			return -1;
		}
		else {

			// Move to the next index.
			return addInDatabase(database->next[position], s, index + 1);
		}
	}
}
vector<string> getUsernames(int n, vector<string> &usernames) {

	// Create a struct/Object of trie.
	trie *database = new trie();

	// Vector to store the final answer.
	vector<string> ans;

	// Iterate through all the usernames.
	for (int i = 0; i < n; i++) {
		int Number = addInDatabase(database, usernames[i], 0);

		// If the number returned is -1, the current username was not in the database.
		if (Number == -1) {
			ans.push_back(usernames[i]);
		}
		else {
			ans.push_back(usernames[i] + to_string(Number));
		}
	}
	return ans;
}
