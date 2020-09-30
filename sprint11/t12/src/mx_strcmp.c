int mx_strcmp(const char *s1, const char *s2) {
    int i = 0;
    int result = 0;
    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] == s2[i]){
            i++;
        } else {
            result = s1[i] - s2[i];
            break;
        }
    }
    return result;
}

