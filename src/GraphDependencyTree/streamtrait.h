/*!
 * \file      streamtrait.h
 * \author    attila.krupl
 * \date      2021/02/24
 */

#pragma once

template<typename S, typename T>
class IsStreamable
{
    template<typename S, typename T>
    static auto test( int )->decltype( std::declval<S&>() << std::declval<T>(), std::true_type() );

    template<typename, typename>
    static auto test( ... )->std::false_type;

public:
    static const bool value = decltype( test<S, T>( 0 ) )::value;
};
