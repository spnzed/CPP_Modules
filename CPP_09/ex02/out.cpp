//

// std::deque<int> mergeStk (std::deque<int> left, std::deque<int> right) {
// 	std::deque<int> ret;

// 	while (!left.empty() && !right.empty()) {
// 		if (left.front() < right.front()) {
// 			ret.push_back(left.front());
// 			left.pop_front();
// 		} else {
// 			ret.push_back(right.front());
// 			right.pop_front();
// 		}
// 	}
	
// 	while (!left.empty()) {
// 		ret.push_back(left.front());
// 		left.pop_front();
// 	}

// 	while (!right.empty()) {
// 		ret.push_back(right.front());
// 		right.pop_front();
// 	}

// 	for (int i = 0; i < int(ret.size()); i++) {
// 		std::cout << ret[i] << "; ";
// 	}
// 	std::cout << std::endl;

// 	return ret;
// }

// std::deque<int> sortMerge (std::deque<int> stk) {

// 	if (stk.size() <= 1) {
// 		return stk;
// 	}
	
// 	std::deque<int> first(stk.begin(), stk.begin() + (stk.size() / 2));
// 	std::deque<int> left = sortMerge(first);
// 	std::deque<int> second(stk.begin() + (stk.size() / 2), stk.end());
// 	std::deque<int> right = sortMerge(second);

// 	return (mergeStk(left, right));
// }

// chain_2 = sortMerge(chain_2); Lo de arriba
