#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

std::string scrape_page(const std::string& url) {
    std::cout << "Scraping: " << url << "...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return "Data from " + url;
}

std::string process_data(const std::string& data) {
    std::cout << "Processing data: " << data << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string processed = "Processed: " + data;
    std::cout << processed << "\n";
    return processed;
}

int main() {
    std::vector<std::string> urls = { "http://page1.com", "http://page2.com", "http://page3.com" };

    // Launch the scraping tasks asynchronously
    std::vector<std::future<std::string>> scrape_results;
    for (const auto& url : urls) {
        scrape_results.push_back(std::async(std::launch::async, scrape_page, url));
    }

    // Launch deferred tasks to process each page's data
    std::vector<std::future<std::string>> process_results;
    for (const auto& url : urls) {
        process_results.push_back(std::async(std::launch::deferred, process_data, "Data from " + url));
    }

    std::cout << "Main thread performing other tasks...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // get result is scraped_data
    std::vector<std::string> scraped_data;
    for (auto& result : scrape_results) {
        scraped_data.push_back(result.get());  // Blocks until the scraping is done
    }

	// nous avons les data scrapees, nous pouvons les traiter
    std::cout << "Data scraping complete. Now processing...\n";
    for (auto& result : process_results) {
        std::string processed = result.get();  // Executes the deferred task (data processing)
        std::cout << "Final processed data: " << processed << "\n";
    }

    return 0;
}
