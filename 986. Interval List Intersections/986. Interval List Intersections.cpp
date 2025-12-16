class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        std::vector<std::vector<int>> answer;   // резервируем память под ответ
        answer.reserve(std::min(firstList.size(), secondList.size()));  // резервируем максимально реально возможное количество пересечений

        auto first_it = firstList.begin();
        auto second_it = secondList.begin();

        while (first_it != firstList.end()) {   // продвигаемся по первому массиву (пока ляюой из них не закончился)

            // проверка перескоки (в конце мы сдигаем второй набор, НО конец второго набора может попадать в след эл из первого набора)
            if (second_it != secondList.begin() && (*(second_it - 1))[0] <= (*first_it)[1] && (*(second_it - 1))[1] >= (*first_it)[0]) {
                --second_it;
            }

            while (second_it != secondList.end() && (*second_it)[1] < (*first_it)[0]) { // ищем потенцильный отрезок среди второго набора (пока не закончится набор)
                second_it++;
            }

            while (second_it != secondList.end() && (*second_it)[0] <= (*first_it)[1]) {    // значит второй набор еще не закончился => продолжаем

                if ((*second_it)[0] <= (*first_it)[0]) { // начинается с (*first_it)[0]

                    if ((*second_it)[1] >= (*first_it)[1]) { // заканчивается на (*first_it)[1]
                        answer.push_back({ (*first_it)[0], (*first_it)[1] });
                    }
                    else {  // заканчивается на (*second_it)[1]
                        answer.push_back({ (*first_it)[0], (*second_it)[1] });
                    }
                }
                else {  // начинается с (*second_it)[0]

                    if ((*second_it)[1] >= (*first_it)[1]) { // заканчивается на (*first_it)[1]
                        answer.push_back({ (*second_it)[0], (*first_it)[1] });
                    }
                    else {  // заканчивается на (*second_it)[1]
                        answer.push_back({ (*second_it)[0], (*second_it)[1] });
                    }
                }

                second_it++;
            }

            first_it++;
        }

        return answer;
    }
};