#include <iostream>
#include <ctime>
#include <string>
#include <openssl/sha.h>

// Block structure
struct Block {
    int index;
    std::string previousHash;
    std::string timestamp;
    std::string data;
    std::string hash;
    int nonce;

    Block(int index, const std::string& previousHash, const std::string& data)
        : index(index), previousHash(previousHash), data(data) {
        timestamp = generateTimestamp();
        nonce = 0;
        mineBlock();
    }

    std::string generateTimestamp() {
        time_t now = time(0);
        char* timeString = ctime(&now);
        return std::string(timeString);
    }

    void mineBlock() {
        while (true) {
            std::string candidateHash = calculateHash();
            if (candidateHash.substr(0, 4) == "0000") {
                hash = candidateHash;
                break;
            }
            nonce++;
        }
    }

    std::string calculateHash() {
        std::string dataToHash = std::to_string(index) + previousHash + timestamp + data + std::to_string(nonce);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256((const unsigned char*)dataToHash.c_str(), dataToHash.length(), hash);
        char hashString[SHA256_DIGEST_LENGTH * 2 + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hashString[i * 2], "%02x", hash[i]);
        }
        return std::string(hashString);
    }
};

// Blockchain class
class Blockchain {
public:
    Blockchain() {
        genesisBlock = createGenesisBlock();
        tail = genesisBlock;
    }

    Block createGenesisBlock() {
        return Block(0, "0", "Genesis Block");
    }

    void addBlock(const std::string& data) {
        int index = tail->index + 1;
        std::string previousHash = tail->hash;
        Block newBlock(index, previousHash, data);
        tail->next = &newBlock;
        tail = &newBlock;
    }

    bool isChainValid() {
        Block* currentBlock = genesisBlock;
        Block* nextBlock = currentBlock->next;
        while (nextBlock) {
            if (nextBlock->previousHash != currentBlock->hash || nextBlock->hash != nextBlock->calculateHash()) {
                return false;
            }
            currentBlock = nextBlock;
            nextBlock = currentBlock->next;
        }
        return true;
    }

    void printChain() {
        Block* currentBlock = genesisBlock;
        while (currentBlock) {
            std::cout << "Block #" << currentBlock->index << "\n";
            std::cout << "Previous Hash: " << currentBlock->previousHash << "\n";
            std::cout << "Timestamp: " << currentBlock->timestamp << "\n";
            std::cout << "Data: " << currentBlock->data << "\n";
            std::cout << "Hash: " << currentBlock->hash << "\n";
            std::cout << "Nonce: " << currentBlock->nonce << "\n\n";
            currentBlock = currentBlock->next;
        }
    }

private:
    Block* genesisBlock;
    Block* tail;
};

int main() {
    Blockchain blockchain;

    blockchain.addBlock("Transaction 1");
    blockchain.addBlock("Transaction 2");
    blockchain.addBlock("Transaction 3");

    blockchain.printChain();

    if (blockchain.isChainValid()) {
        std::cout << "Blockchain is valid.\n";
    } else {
        std::cout << "Blockchain is not valid.\n";
    }

    return 0;
}
