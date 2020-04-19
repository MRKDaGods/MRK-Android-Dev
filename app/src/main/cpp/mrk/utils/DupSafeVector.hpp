#include <vector>
#include <algorithm>

namespace MRK
{
    namespace Utils
    {
        template<typename T>
        class DupSafeVector : public _STD vector<T>
        {
        public:
            void add(T element)
            {
                auto x = _STD find(this->begin(), this->end(), element);
                if (x == this->end())
                    this->push_back(element);
            }
        };
    }
}