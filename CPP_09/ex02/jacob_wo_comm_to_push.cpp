// Función para insertar con el algoritmo de Jacobsthal usando std::deque
void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size) {

    std::cout << std::endl;
    std::cout << YELLOW << "-----------------------------------------------------------------" << RESET << std::endl;
    std::cout << std::endl;

    std::deque<int> chain_B = getStack(stack, int(stack.size()), group_size, 1);
    printDeque(stack, group_size, "Full Stack");

    chain_B.insert( chain_B.begin(), stack.begin(), stack.begin() + group_size );

    printDeque(chain_B, group_size, "Stack b (AFTER FIRST INSERTION)");

    int prev = 1;
    int limit = 0;

    std::cout << "END: " << end << std::endl;
    int it_end = end / group_size;

    std::vector<int> j_numbers = jacobsthal(it_end);

    for (int i = 1; i < it_end; i+=2) {
        if (j_numbers[i] <= it_end && j_numbers[i])
            limit += ((((j_numbers[i]) * group_size) * 2)) - 1;

        while (limit > end) {
            limit = ((it_end - 2) * group_size) -1;
        }

        for (int j = limit; j > prev && j <= end; j-=(group_size * 2)) {
            std::cout << "J: " << j / group_size << " > " << prev << " && " << j << " <= " << end << std::endl;
            std::cout << " in J - 1 [ " << stack[ j - 1 ] << " " << stack[ j + group_size - 1] << " ] " << std::endl;
            
            int a_value = stack[j + group_size];

            int b_value = 0;
            if (j + group_size + group_size > int(stack.size())) {
                b_value = -1;
            } else {
                b_value = stack[j + group_size + group_size];
            }

            int b_position = search_pos(b_value, chain_B, group_size);

            int insert_pos = binarySearch(chain_B, b_position, a_value, group_size);
            
            std::cout << std::endl;
            std::cout << BLUE << "Insert stack:\t[" << stack[j + 1] << "\t...\t" << stack[j + group_size] << "]" << RESET << std::endl;
            std::cout << "\t\t\t\t↓" << std::endl;
            std::cout << RED << "Insert Behind:\t[" << chain_B[insert_pos] << "\t...\t" << chain_B[insert_pos + group_size - 1] << "]" << RESET << std::endl;
            std::cout << std::endl;

            std::deque< int >::iterator first = stack.begin() + j + 1;
            std::deque< int >::iterator second = stack.begin() + j + group_size + 1;

            chain_B.insert( chain_B.begin() + insert_pos, first, second);
            printDeque(chain_B, group_size, "Stack b (AFTER JACOB)");

            if (j - (group_size * 2) <= prev) 
                prev = limit;
        }
    }
    stack = chain_B;
}