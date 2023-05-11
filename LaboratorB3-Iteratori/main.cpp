#include "CsvReader.h"
#include <utility>
#include <vector>

class Episode
{
public:
    std::string title;
    std::string date;
    std::string length;
    std::string viewersmm;
    int score;

    Episode(std::string _title, std::string _date, std::string _length, std::string _viewersmm, int _score) \
    : title(std::move(_title)), date(std::move(_date)), length(std::move(_length)), viewersmm(std::move(_viewersmm)), score(_score) {}
};

int main() {
    std::ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        printf("File couldn't be opened\n");
        return 1;
    }
    CsvReader reader(input_file);

    std::vector<Episode> episodes;
    for (std::vector<std::string> columns : reader) {
        Episode newEpisode(columns[0],columns[1],columns[2],columns[3],std::atoi(columns[4].c_str()));
        episodes.emplace_back(newEpisode);
    }

    printf("number of episodes: %zu\n\n", episodes.size());

    std::ofstream output_file("output.txt");
    for (auto& [title, date, length, viewersmm, score] : episodes) {
        printf("%s,%s,%s,%s,%d\n", title.c_str(), date.c_str(), length.c_str(), viewersmm.c_str(), score);
    }
}