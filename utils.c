
double ft_atof(const char *str) {
  double res = 0.0;
  double dec_part = 0.0;
  int sign = 1;
  int i = 0;
  int decimal_places = 0;  // Flag to indicate decimal point encountered

  // Check for sign
  if (*str == '+' || *str == '-') {
    if (*str++ == '-') {
      sign = -1;
    }
  }

  // Skip leading whitespaces
  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r') {
    i++;
  }

  // Extract integer part
  while (str[i] >= '0' && str[i] <= '9') {
    res = res * 10 + (str[i] - '0');
    i++;
  }

  // Check for decimal point
  if (str[i] == '.') {
    i++;
    decimal_places = 1;  // Set flag if decimal point is encountered
  }

  // Extract decimal part (without pow)
  while (str[i] >= '0' && str[i] <= '9') {
    dec_part = dec_part * 10 + (str[i] - '0');
    if (decimal_places) {
      decimal_places++;  // Count decimal places for weighting
    }
    i++;
  }

  // Handle decimal places (manual weighting)
  if (decimal_places) {
    int divisor = 1;
    for (int j = 0; j < decimal_places; j++) {
      divisor *= 10;
    }
    dec_part /= divisor;  // Divide by 10 raised to the power of decimal places
  }

  // Combine integer and decimal parts
  res += dec_part;

  // Return the converted value with sign
  return res * sign;
}
int ft_strcmp(const char *s1, const char *s2) {
  while (*s1 && *s2) {
    if (*s1 != *s2) {
      return *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return *s1 - *s2;
}