#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace gfxcpp {

class object {
public:
    object();
    virtual ~object();

    virtual void update() = 0;
    virtual void render() = 0;

private:
};

} // namespace gfxcpp

#endif // OBJECT_HPP
