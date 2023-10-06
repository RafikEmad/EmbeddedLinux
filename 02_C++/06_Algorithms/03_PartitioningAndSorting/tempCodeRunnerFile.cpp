std::partial_sort_copy(
        numbers.begin(), numbers.end(),
        partialSortCopyNumbers.begin(), partialSortCopyNumbers.end(),
        [](int a, int b) {
            return a < b;
        }
    );