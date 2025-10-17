void strncpy(char* dest, const char* src, size_t n) {
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	for (; i < n; i++) {
		dest[i] = '\0';
	}
}
int strcmp(char* str1, char* str2) {
	size_t i;
	for (i = 0; i < sizeof(str1); i++) {
		if (str1[i] != str2[i]) {
			return (unsigned char)str1[i] - (unsigned char)str2[i];
		}
		if (str1[i] == '\0') {
			return 0;
		}
	}
	return 0;
}