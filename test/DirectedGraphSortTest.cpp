#include "DirectedGraph.h"

#include "gtest/gtest.h"

TEST(topology_sort, print_test) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 0, 1 }, { 0, 3 }, { 1, 2 },
                    { 1, 3 }, { 2, 4 }, {3, 4}
            };

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    graph.printGraph();
}

TEST(topology_sort, test_5_nodes) {

	Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 0, 1 }, { 0, 3 }, { 1, 2 },
                    { 1, 3 }, { 2, 4 }, {3, 4}
            };

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));

	auto v = graph.topologySort();

    vector<int> ans1{0, 1, 3, 2, 4,};
    vector<int> ans2{0, 1, 2, 3, 4,};

    ASSERT_TRUE((*v)==ans1 || (*v)==ans2);

    delete v;

	
}

TEST(topology_sort, test_2_nodes) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 1, 0 }
            };

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
   
	auto v = graph.topologySort();

    vector<int> ans{1, 0};
	
    ASSERT_TRUE((*v)==ans);
	
    delete v;

}

TEST(topology_sort, test_provided_case) {
	Edge edges[] =
	{
					// pair (x, y) represents edge from x to y
					{ 7, 6 }, { 7, 5 }, { 6, 4 },
					{ 5, 4 }, { 6, 3 }, { 5, 2 },
					{ 3, 1 }, { 2, 1 }, { 1, 0 }
	};

	DirectedGraph graph(edges, sizeof(edges) / sizeof(edges[0]));
	auto v = graph.topologySort();

	// all possible answer vectors for the provided test case
	vector<int> ans1 { 7, 6, 5, 4, 3, 2, 1, 0 };
	vector<int> ans2 { 7, 6, 5, 4, 2, 3, 1, 0 };
	vector<int> ans3 { 7, 6, 5, 2, 3, 4, 1, 0 };
	vector<int> ans4 { 7, 6, 5, 2, 4, 3, 1, 0 };
	vector<int> ans5 { 7, 6, 5, 3, 2, 4, 1, 0 };
	vector<int> ans6 { 7, 6, 5, 3, 4, 2, 1, 0 };
	vector<int> ans7 { 7, 5, 6, 4, 3, 2, 1, 0 };
	vector<int> ans8 { 7, 5, 6, 3, 4, 2, 1, 0 };
	vector<int> ans9 { 7, 5, 6, 4, 2, 3, 1, 0 };
	vector<int> ans10{ 7, 5, 6, 2, 4, 3, 1, 0 };
	vector<int> ans11{ 7, 5, 6, 2, 3, 4, 1, 0 };
	vector<int> ans12{ 7, 5, 6, 3, 2, 4, 1, 0 };

	// instead of creating a massive || statement, pushing these vectors into another vector that 
	// we can loop through for testing instead
	vector<vector<int>> answers;
	answers.push_back(ans1);
	answers.push_back(ans2);
	answers.push_back(ans3);
	answers.push_back(ans4);
	answers.push_back(ans5);
	answers.push_back(ans6);
	answers.push_back(ans7);
	answers.push_back(ans8);
	answers.push_back(ans9);
	answers.push_back(ans10);
	answers.push_back(ans11);
	answers.push_back(ans12);

	// keeps track of if we have a matching vector or not
	bool matched = false;

	// loops through the vector that houses all the vector answers
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == *v) { // if one of these vectors matches topologySort, we have matched
			matched = true;
		}
	}

	// now just asserts if we have correctly found a match or not
	ASSERT_TRUE(matched);
	delete v;
}