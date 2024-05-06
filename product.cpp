#include "product.h"

Product::Product(const QString &name, double price, const QString &size, const QString &material, const QString &color)
    : m_name(name), m_price(price), m_size(size), m_material(material), m_color(color)
{
}

QString Product::name() const
{
    return m_name;
}

double Product::price() const
{
    return m_price;
}

QString Product::size() const
{
    return m_size;
}

QString Product::material() const
{
    return m_material;
}

QString Product::color() const
{
    return m_color;
}

