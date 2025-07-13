#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <sstream>

int readFileIntoString(const std::string& filename, std::string& file_contents);
int readStringIntoFile(const std::string& filename_r, std::string& file_contents);
void ft_replace(std::string& file_contents, const std::string& s1, const std::string& s2);

#endif