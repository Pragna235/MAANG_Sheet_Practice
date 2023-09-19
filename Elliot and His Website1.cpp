/*
    Time Complexity : O(|S|*N^3)
    Space Complexity : O(N*|S|)

    Where, |S| is the maximum length of the strings and N is the total number of strings.
*/

vector<string> getUsernames(int n, vector<string> &usernames) {

	// Vector to store all the final usernames.
	vector<string> database;

	// Iterate through all the given usernames.
	for (int i = 0; i < n; i++) {
		bool isPresent = 0;

		// check if current username is present in the database or not.
		for (int j = 0; j < database.size(); j++) {
			if (usernames[i] == database[j]) {
				isPresent = 1;
			}
		}

		// If not present, push in the database.
		if (isPresent == 0) {
			database.push_back(usernames[i]);
			continue;
		}

		int count = 0;

		// Increment count till we found a unique username.
		while (true) {

			// String to store the username to be checked.
			string check = usernames[i];
			check += to_string(count);
			int isNumPresent = 0;
			for (int j = 0; j < database.size(); j++) {
				if (check == database[j]) {
					isNumPresent = 1;
				}
			}

			// If not present, push in the database.
			if (isNumPresent == 0) {
				database.push_back(check);
				break;
			}
			count++;
		}
	}
	return database;
}

