/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:14:51 by jadithya          #+#    #+#             */
/*   Updated: 2023/10/16 15:45:35 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "contact.class.cpp"

class	PhoneBook {
	private:
		void	PrintContacts(void);

	public:
		Contact List[8];
		int		NumContacts;

		PhoneBook(void);
		~PhoneBook();

		void	AddContact();
		void	SearchContact();
};

#endif