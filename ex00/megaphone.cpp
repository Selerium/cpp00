/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:31:26 by jadithya          #+#    #+#             */
/*   Updated: 2023/10/16 12:31:25 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	std::string	str;
	int			start;
	int			end;

	if (argc < 2) {
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++) {
		str = argv[i];
		if (str.length() == 0)
			continue ;
		start = str.find_first_not_of(" \t\r\v\f\n");
		end = str.find_last_not_of(" \t\r\v\f\n");
		if (start == (int) std::string::npos || end == (int) std::string::npos)
			continue ;
		str = str.substr(start, end - start + 1);
		for (int j = 0; str[j]; j++) {
			std::cout<<(char) toupper(str[j]);
		}
		std::cout<<" ";
	}
	std::cout<<std::endl;
	return (0);
}