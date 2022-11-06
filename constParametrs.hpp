#ifndef CONSTPARAMETRS_HPP
#define CONSTPARAMETRS_HPP

class constParametrs {
public:
    float weight;

    float length;

    float width;

    constParametrs(float weight, float length, float width);

	constParametrs();

    constParametrs(const constParametrs &);

};
#endif // !CONSTPARAMETRS_HPP