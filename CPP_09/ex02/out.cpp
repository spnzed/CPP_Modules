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

    // // Insertar los valores `b` en el orden de Jacobsthal
    // for (int i = 1; i < mid; i++) {
    //     int b_value = to_sort[i].right;

    //     // Calcula el rango hasta donde insertar usando el número de Jacobsthal
	// 	int limit = 0;

    //     if (j_numbers[i] < int(chain.size()))
	// 		limit = j_numbers[i];
	// 	else
	// 		limit = int(chain.size());

    //     // Usar customUpperBound para buscar la posición de inserción para `b_value`
    //     int insert_pos = customUpperBound(chain, 0, limit, b_value);

    //     // Insertar el valor `b` en la posición encontrada
    //     chain.insert(chain.begin() + insert_pos, b_value);
    // }





		// for (int j = limit - 1; j > 1 ; j--) {
		// 	if (j > prev && j < mid) {
		// 		int b_value = to_sort[j].left;

		// 		// Usar customUpperBound para buscar la posición de inserción para `b_value`
		// 		int insert_pos = customUpperBound(chain, 0, limit, b_value);

		// 		std::cout << "Limit " << limit << std::endl;
		// 		std::cout << "Inserting " << b_value << " at position " << insert_pos << std::endl;

		// 		// Insertar el valor `b` en la posición encontrada
		// 		chain.insert(chain.begin() + insert_pos, b_value);	
		// 	} else {
		// 		break ;
		// 	}
		// }

		// if (limit == int(chain.size()))
		// 	break ;
		// else
		// if (limit == int(chain.size())) {
		// 	break;
		// }