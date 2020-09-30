FROM php:7.4-cli

ENV CODE /code
# 设置工作目录
WORKDIR $CODE

RUN sed -i "s@http://deb.debian.org@http://mirrors.aliyun.com@g" /etc/apt/sources.list && \
    apt-get -y update && \
    apt-get install -y wget git && \
    docker-php-ext-install pcntl

COPY ./ServerPhp $CODE
RUN wget https://raw.githubusercontent.com/composer/getcomposer.org/76a7060ccb93902cd7576b67264ad91c8a2700e2/web/installer -O - -q | php -- --quiet && \
    mv composer.phar /usr/local/bin/composer && \
    php -r "unlink('installer');" && \
    composer install

CMD [ "php", "index.php", "start"]
