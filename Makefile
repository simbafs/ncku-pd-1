clean:
	find . -type f -executable -exec rm {} +
	find . -name testcase -exec rm {} +
