/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/23 17:02:24 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "headers.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator				iterator;
		typedef typename std::deque<T>::const_iterator			const_iterator;
		typedef typename std::deque<T>::reverse_iterator		reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;

		MutantStack() : std::stack<T>(){}
		MutantStack(const T* arr, size_t size){
			for (size_t i = 0; i < size; ++i)
				this->push(arr[i]);}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy){}
		~MutantStack(){}
		MutantStack& operator=(const MutantStack &other){
			if (this != &other) {
				std::stack<T>::operator=(other);}
			return (*this);};

		iterator begin(){
			return this->c.begin();}
		iterator end(){
			return this->c.end();}
		const_iterator begin() const{
			return this->c.begin();}
		const_iterator end() const{
			return this->c.end();}
		reverse_iterator rbegin(){
			return this->c.rbegin();}
		reverse_iterator rend(){
			return this->c.rend();}
		const_reverse_iterator rbegin() const{
			return this->c.rbegin();}
		const_reverse_iterator rend() const{
			return this->c.rend();}
};

#endif
