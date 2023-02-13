/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:11:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/13 19:08:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

//Program replaces a string s1 in filename by a string s2 and writes to new file.
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		// Take program inputs.
		std::string		filename = argv[1];
		std::string		string1 = argv[2];
		std::string		string2 = argv[3];

		// Open the file for reading.
		std::fstream	infile;
		
		infile.open(filename.c_str(), std::ios::in);
		if (!infile)
		{
			std::cout << "Error reading file\n";
			infile.close();
			return (1);
		}
		else
			std::cout << "Input file read.\n";
		
		// Read the file contents to a string.
		std::string		inLine, inContents;

		while (infile)
		{
			std::getline(infile, inLine);
			inContents.append(inLine);
			inContents.append("\n");
		}
		inContents.erase(inContents.end() - 1);
		infile.close();

		// Replace the substrings within the string to build the new string.
		std::string		outContents;
		std::size_t		find, pos = 0;

		while (pos < inContents.length())
		{
			find = inContents.find(string1, pos);
			if (find == std::string::npos)
			{
				outContents.append(inContents.substr(pos));
				break ;
			}
			outContents.append(inContents.substr(pos, find - pos));
			outContents.append(string2);
			pos = find + string1.length();
		}

		// Write the output file.
		std::fstream	outfile;
		outfile.open(filename.append(".replace").c_str(), std::ios::out);
		if (!outfile)
		{
			std::cout << "Error creating output file.\n";
			outfile.close();
			return (1);
		}
		else
			std::cout << "Created output file.\n";
		outfile << outContents;
		outfile.close();
	}
	else
	{
		std::cout << "Invalid number of arguments." << std::endl;
		return (1);
	}
	return (0);
}
