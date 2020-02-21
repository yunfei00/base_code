#!/usr/bin/python
# -- coding: utf-8 --

import logging
version = "1.0.0 finish basic function"

class Logger(object):
    def __init__(self):
        self.logger = logging.getLogger('log')
        self.logger.setLevel(logging.DEBUG)

        # create console handler and set level to debug
        ch = logging.StreamHandler()
        ch.setLevel(logging.INFO)

        # create file handler and set level to debug
        fh = logging.FileHandler("log.txt")
        fh.setLevel(logging.DEBUG)

        # create formatter
        #formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        formatter = logging.Formatter(fmt='%(asctime)s %(levelname)-7s %(message)s {filename:%(filename)s func:%(funcName)s line:%(lineno)d }', datefmt='%Y-%m-%d %H:%M:%S')

        # add formatter to ch
        ch.setFormatter(formatter)
        fh.setFormatter(formatter)

        # add ch to logger
        # add fh to logger
        self.logger.addHandler(ch)
        self.logger.addHandler(fh)

        self.debug = self.logger.debug
        self.info = self.logger.info
        self.warning = self.logger.warning
        self.error = self.logger.error
        self.critical = self.logger.critical
   
logger = Logger()
if __name__ == '__main__':
    logger = Logger()
    logger.info("info")
    logger.debug("debug level")
    logger.warning("warning")
    logger.error("error level")
