#include "presentation.hpp"

std::vector<Slide*> slides() const { return m_slides; }

void Slide::addSlide(size_t idx, const Slide& slide) {
    if (idx > m_slides.size())
        return;

    try {
        auto it = m_slides.begin() + idx;
        m_slides.insert(it, shape);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Slide::removeSlide(size_t idx) {
    if (idx >= m_slides.size())
        return;

    auto it = m_slides.begin() + idx;
    m_slides.erase(it);
}

Slide* Slide::getSlide(size_t idx) {
    if (idx >= m_slides.size())
        return;

    return m_slides[idx];
}