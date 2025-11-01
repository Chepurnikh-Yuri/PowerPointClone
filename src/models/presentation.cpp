#include "presentation.hpp"

std::vector<Slide*> Presentation::slides() const {
    std::vector<Slide*> slides;
    slides.reserve(m_slides.size());

    for (const auto& s : m_slides)
        slides.push_back(s.get());

    return slides;
}

void Presentation::addSlide(size_t idx, const Slide& slide) {
    if (idx > m_slides.size())
        return;

    try {
        auto it = m_slides.begin() + idx;
        m_slides.insert(it, std::make_unique<Slide>(std::move(slide)));
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Presentation::removeSlide(size_t idx) {
    if (idx >= m_slides.size())
        return;

    auto it = m_slides.begin() + idx;
    m_slides.erase(it);
}

Slide* Presentation::getSlide(size_t idx) {
    if (idx >= m_slides.size())
        return nullptr;

    return m_slides[idx].get();
}